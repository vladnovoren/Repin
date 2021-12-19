#include "gui_select_button.hpp"
#include "gui_widget_manager.hpp"
#include "gui_select_panel.hpp"


gui::SelectButton::SelectButton(const glib::IntRect& location):
                   AbstractButton(location) {}


gui::SelectButton::SelectButton(const glib::IntRect& location,
                                AbstractButtonSkin* skin):
                   AbstractButton(location, skin) {}


gui::SelectButton::SelectButton(const glib::IntRect& location,
                                AbstractWidgetFunctor* functor,
                                AbstractButtonSkin* skin):
                   AbstractButton(location, functor, skin) {
  assert(functor != nullptr);
  assert(skin != nullptr);
}


gui::SelectButton::SelectButton(const glib::IntRect &location,
                                AbstractWidgetFunctor *functor,
                                AbstractButtonSkin *skin, SelectPanel *owner):
                   AbstractButton(location, functor, skin), m_owner(owner) {
  assert(functor != nullptr);
  assert(skin != nullptr);
  assert(owner != nullptr);
}


gui::EventResult gui::SelectButton::OnMouseButtonPressed(glib::Vector2i,
                                                         glib::Vector2i,
                                                         MouseButton button) {
  assert(m_skin != nullptr);

  if (button == MouseButton::LEFT) {
    m_is_selected = true;
    WidgetManager::GetInstance().AddMouseActiveWidget(this);
    m_skin->SetPressed();
    m_needs_to_render = true;
    return EventResult::PROCESSED;
  }
  return EventResult::NOT_PROCESSED;
}


gui::EventResult gui::SelectButton::OnMouseMove(glib::Vector2i new_local_mouse_position,
                                                glib::Vector2i) {
  WidgetManager& widget_manager = WidgetManager::GetInstance();
  if (IsPointInside(new_local_mouse_position)) {
    if (widget_manager.GetMouseActiveWidget() != this && !m_is_selected) {
      m_skin->SetHovered();
      m_needs_to_render = true;
    }
  } else {
    if (!m_is_selected) {
      m_skin->SetIdle();
      m_needs_to_render = true;
      if (widget_manager.GetMouseActiveWidget() == this) {
        widget_manager.RemoveMouseActiveWidget(this);
      }
    }
  }
  return EventResult::NOT_PROCESSED;
}


gui::EventResult gui::SelectButton::OnMouseButtonReleased(glib::Vector2i local_mouse_position,
                                                          glib::Vector2i,
                                                          MouseButton button) {
  if (button == MouseButton::LEFT) {
    WidgetManager& widget_manager = WidgetManager::GetInstance();
    if (this == widget_manager.GetMouseActiveWidget()) {
      m_is_selected = false;
      widget_manager.RemoveMouseActiveWidget(this);
      m_needs_to_render = true;
    }
    if (IsPointInside(local_mouse_position) && m_is_selected) {
      assert(m_functor != nullptr);
      m_is_selected = true;
      m_owner->SetActiveButton(this);
      m_functor->operator()();
    }
  }
  return EventResult::PROCESSED;
}


bool gui::SelectButton::IsSelected() const {
  return m_is_selected;
}


void gui::SelectButton::SetIdle() {
  AbstractButton::SetIdle();
  m_is_selected = false;
}


void gui::SelectButton::SetOwner(SelectPanel *owner) {
  assert(owner != nullptr);

  m_owner = owner;
}
