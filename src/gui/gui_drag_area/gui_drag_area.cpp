#include "gui_drag_area.hpp"


gui::DragArea::DragArea(DefaultViewSkin* skin):
               AbstractView(skin) {
  assert(skin != nullptr);
}


void gui::DragArea::OnMouseMove(glib::Vector2i new_mouse_position) {
  if (m_is_under_press) {
    
  }
}
