#include "gui_button.hpp"
#include "gui_view_manager.hpp"


// Button
//==============================================================================
gui::Button::Button(AbstractViewFunctor* functor, AbstractButtonSkin* skin):
             m_functor(functor), m_skin(skin) {
  assert(functor != nullptr);
  assert(skin    != nullptr);
}


gui::Button::~Button() {
  delete m_skin;
  delete m_functor;
}


bool gui::Button::IsPointInside(glib::Vector2i point) const {
  return m_skin->IsPointInside(m_location, point);
}


void gui::Button::SetSkin(AbstractButtonSkin* skin) {
  assert(skin);

  delete(m_skin);
  m_skin = reinterpret_cast<AbstractButtonSkin*>(skin->Copy());
  m_skin->SetIdle();
}


void gui::Button::SetFunctor(AbstractViewFunctor* functor) {
  assert(functor);

  m_functor = functor;
}


void gui::Button::Draw(glib::RenderTarget* render_target,
                       const glib::Vector2i& position) {
  assert(render_target);

  if (m_needs_to_render) {
    m_skin->Render(m_location.m_size);
    m_needs_to_render = false;
  }
  glib::Vector2i position_to_copy = position + m_location.m_position;
  m_skin->CopyToRenderTarget(render_target, position_to_copy);
}


gui::EventResult gui::Button::OnMouseButtonPressed(glib::Vector2i,
                                                   MouseButton button) {
  if (button == MouseButton::LEFT) {
    ViewManager::GetInstance().AddMouseActiveView(this);
    m_skin->SetPressed();
    m_needs_to_render = true;
    return EventResult::PROCESSED;
  }
  return EventResult::NOT_PROCESSED;
}


gui::EventResult gui::Button::OnMouseMove(glib::Vector2i new_mouse_position) {
  ViewManager& view_manager = ViewManager::GetInstance();
  if (IsPointInside(new_mouse_position)) {
    if (view_manager.GetMouseActiveView() != this) {
      m_skin->SetHovered();
      m_needs_to_render = true;
    }
  } else {
    m_skin->SetIdle();
    m_needs_to_render = true;
    if (view_manager.GetMouseActiveView() == this) {
      view_manager.RemoveMouseActiveView(this);
    }
  }
  return EventResult::NOT_PROCESSED;
}


gui::EventResult gui::Button::OnMouseButtonReleased(glib::Vector2i mouse_position,
                                                    MouseButton button) {
  if (button == MouseButton::LEFT) {
    ViewManager& view_manager = ViewManager::GetInstance();
    if (this == view_manager.GetMouseActiveView()) {
      view_manager.RemoveMouseActiveView(this);
    }
    if (IsPointInside(mouse_position)) {
      m_functor->operator()();
      m_skin->SetHovered();
    } else {
      m_skin->SetIdle();
    }
    m_needs_to_render = true;
  }
  return EventResult::PROCESSED;
}
//==============================================================================
