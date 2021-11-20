#include "gui_drag_area.hpp"


gui::DragArea::DragArea(DefaultViewSkin* skin):
               AbstractView(skin) {
  assert(skin != nullptr);
}


void gui::DragArea::OnMouseMove(glib::Vector2i new_mouse_position) {
  new_mouse_position -= m_skin->m_location.m_position;
  if (m_is_under_press) {
    m_drag_area_functor(new_mouse_position - m_curr_mouse_position);
    m_curr_mouse_position = new_mouse_position;
  }
}


void gui::DragArea::OnLeftMouseButtonPressed(glib::Vector2i mouse_position) {
  mouse_position -= m_skin->m_location.m_position;
  m_curr_mouse_position = mouse_position;
  m_is_under_press = true;
}


void gui::DragArea::OnLeftMouseButtonReleased(glib::Vector2i) {
  m_is_under_press = false;
}
