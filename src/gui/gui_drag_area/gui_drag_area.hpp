#ifndef GUI_DRAG_AREA_HPP
#define GUI_DRAG_AREA_HPP


#include "glib.hpp"
#include "gui_abstract_view.hpp"


namespace gui {
  class DragArea: public AbstractView {
   public:
    DragArea() = default;
    DragArea(const glib::UIntRect& location);
    ~DragArea() = default;

    void OnMouseMove(const glib::Vector2u& new_mouse_position);
  };
}


#endif /* gui_drag_area.hpp */