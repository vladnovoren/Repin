#ifndef GUI_DRAG_AREA_HPP
#define GUI_DRAG_AREA_HPP


#include "glib.hpp"
#include "gui_abstract_view.hpp"


namespace gui {
  class DragArea: {
   public:
    DragArea() = default;
    DragArea(const glib::UIntRect& location);
    ~DragArea() = default;

    EventResult OnMouseMove();
  };
}


#endif /* gui_drag_area.hpp */