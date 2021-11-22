#include "gui_window.hpp"


gui::Window::Window(DefaultViewSkin* skin, TitleBar* title_bar):
             m_skin(skin), m_title_bar(title_bar) {
  assert(skin != nullptr);
  assert(title_bar != nullptr);
}


void gui::Window::OnLeftMouseDrag(glib::Vector2i new_mouse_position) {
  glib::Vector2i new_mouse_position_inside = new_mouse_position - m_skin->m_location.m_position;
  if (m_child_under_mouse_pressed != nullptr) {
    m_child_under_mouse_pressed->OnLeftMouseDrag(new_mouse_position_inside);
    if (m_child_under_mouse_pressed->m_mouse_press_state == MousePressState::IDLE) {
      m_child_under_mouse_pressed = nullptr;
      for (auto child_it = m_children.begin(); child_it != m_children.end(); ++child_it) {
        auto child_ptr = *child_it;
        if (child_ptr->IsPointInside(new_mouse_position_inside)) {
          child_ptr->OnMouseHoverBegin(new_mouse_position_inside);
          m_child_under_mouse_hovered = child_ptr;
        }
      }
    }
  }
  m_curr_mouse_position = new_mouse_position_inside;
}
