#ifndef GUI_DRAG_AREA_HPP
#define GUI_DRAG_AREA_HPP


#include "glib.hpp"
#include "gui_abstract_view.hpp"
#include "gui_abstract_view_functor.hpp"


namespace gui {
  class DragArea: public AbstractView {
   protected:
    glib::Vector2i curr_mouse_position;
   public:
    DragArea() = default;
    DragArea(DefaultViewSkin* skin);
    ~DragArea() override = default;

    void OnMouseMove(glib::Vector2i new_mouse_position) override;
    void OnLeftMouseButtonPressed(glib::Vector2i mouse_position) override;
    void OnLeftMouseButtonReleased(glib::Vector2i mouse_position) override;
    void OnMouseHoverBegin(glib::Vector2i mouse_position) override;
    void OnMouseHoverEnd(glib::Vector2i mouse_position) override;
  };
}


#endif /* gui_drag_area.hpp */
