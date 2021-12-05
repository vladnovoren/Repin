#include "gui_title_bar.hpp"
#include "gui_widget_manager.hpp"


gui::TitleBar::TitleBar(TitleBarSkin* skin):
               m_skin(skin) {
  assert(skin);
}


gui::TitleBar::~TitleBar() {
  delete(m_skin);
}


gui::EventResult gui::TitleBar::OnMouseButtonPressed(glib::Vector2i mouse_position, MouseButton button) {
  glib::Vector2i mouse_position_inside = mouse_position - m_location.m_position;
  for (auto child_it =  m_children.begin();
            child_it != m_children.end();
            ++child_it) {
    auto child_ptr = *child_it;
    assert(child_ptr != nullptr);
    if (child_ptr->IsPointInside(mouse_position_inside)) {
      return child_ptr->OnMouseButtonPressed(mouse_position_inside, button);
    }
  }
  if (button == MouseButton::LEFT) {
    m_is_dragging = true;
  }
  m_old_mouse_position = mouse_position;
  WidgetManager::GetInstance().AddMouseActiveWidget(this);
  return EventResult::PROCESSED;
}


gui::EventResult gui::TitleBar::OnMouseMove(glib::Vector2i new_mouse_position) {
  if (m_is_dragging) {
    Move(new_mouse_position - m_old_mouse_position);
  } else {
    glib::Vector2i new_mouse_position_inside = new_mouse_position -
                                               m_location.m_position;
    for (auto child_it =  m_children.begin();
              child_it != m_children.end();
              ++child_it) {
      auto child_ptr = *child_it;
      assert(child_ptr != nullptr);
      child_ptr->OnMouseMove(new_mouse_position_inside);
    }
  }
  m_old_mouse_position = new_mouse_position;
  return EventResult::PROCESSED;
}


gui::EventResult gui::TitleBar::OnMouseButtonReleased(glib::Vector2i, MouseButton button) {
  WidgetManager& widget_manager = WidgetManager::GetInstance();
  if (button == MouseButton::LEFT) {
    m_is_dragging = false;
    if (this == widget_manager.GetMouseActiveWidget()) {
      widget_manager.RemoveMouseActiveWidget(this);
    }
  }
  return EventResult::PROCESSED;
}


void gui::TitleBar::Draw(glib::RenderTarget* render_target,
                         const glib::Vector2i& position) {
  assert(render_target != nullptr);

  glib::Vector2i position_inside = position + m_location.m_position;

  if (m_needs_to_render) {
    m_skin->Render(m_location.m_size);
    m_needs_to_render = false;
  }
  m_skin->CopyToRenderTarget(render_target, position_inside);

  for (auto child_it =  m_children.begin();
            child_it != m_children.end();
            ++child_it) {
    auto child_ptr = *child_it;
    assert(child_ptr != nullptr);

    child_ptr->Draw(render_target, position_inside);
  }
}


void gui::TitleBar::SetSkin(TitleBarSkin* skin) {
  assert(skin != nullptr);

  delete(m_skin);
  m_skin = new TitleBarSkin(*skin);
}


void gui::TitleBar::AddMinimizeButton(Button* minimize_button) {
  assert(minimize_button != nullptr);

  minimize_button->m_parent_widget = this;
  m_children.push_front(minimize_button);
}


void gui::TitleBar::AddMaximizeButton(Button* maximize_button) {
  assert(maximize_button != nullptr);

  maximize_button->m_parent_widget = this;
  m_children.push_front(maximize_button);
}


void gui::TitleBar::AddCloseButton(Button* close_button) {
  assert(close_button != nullptr);

  close_button->m_parent_widget = this;
  m_children.push_front(close_button);
}
