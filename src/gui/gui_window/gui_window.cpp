#include "gui_window.hpp"


gui::Window::Window(DefaultViewSkin* skin, TitleBar* title_bar):
             m_skin(skin), m_title_bar(title_bar) {
  assert(skin != nullptr);
  assert(title_bar != nullptr);
}


void gui::Window::OnMouseMove(glib::Vector2i new_mouse_position) {
  if (m_child_under_mouse_press == m_title_bar) {
    if (m_title_bar->m_mouse_press_state == MousePressState::PRESSED) {
      m_title_bar->m_move_functor();
    }
  }
}


void gui::Window::OnMouseHoverBegin(glib::Vector2i mouse_position) {
  glib::Vector2i mouse_position_inside = mouse_position - m_skin->m_location.m_position;
  m_mouse_press_state = MousePressState::HOVERED;
  for (auto child_ptr: m_children) {
    if (child_ptr->IsPointInside(mouse_position_inside)) {
      child_ptr->OnMouseHoverBegin(mouse_position_inside);
      m_child_under_mouse_press = child_ptr;
    }
  }
}


void gui::Window::OnMouseHoverEnd(glib::Vector2i mouse_position) {
  glib::Vector2i mouse_position_inside = mouse_position - m_skin->m_location.m_position;
  m_mouse_press_state = MousePressState::IDLE;
  if (m_child_under_mouse_press != nullptr) {
    m_child_under_mouse_press->OnMouseHoverEnd(mouse_position_inside);
    m_child_under_mouse_press = nullptr;
  }
}
