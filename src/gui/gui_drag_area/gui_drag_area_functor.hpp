#ifndef GUI_DRAG_AREA_FUNCTOR_HPP
#define GUI_DRAG_AREA_FUNCTOR_HPP


#include "gui_abstract_view_functor.hpp"


namespace gui {
  class Window;

  class DragAreaFunctor: public AbstractViewFunctor {
   protected:
    Window* m_owner = nullptr;
    glib::Vector2i m_delta_position;
   public:
    DragAreaFunctor() = default;
    DragAreaFunctor(Window* owner);
    ~DragAreaFunctor() = default;

    void SetDeltaPosition(const glib::Vector2i& delta_position);

    void operator()() override;
    void operator()(const glib::Vector2i& delta_position);
  };
}



#endif /* gui_drag_area_functor.hpp */
