#ifndef GUI_DRAG_AREA_FUNCTOR_HPP
#define GUI_DRAG_AREA_FUNCTOR_HPP


#include "gui_abstract_view_functor.hpp"


namespace gui {
  class Window;

  class DragAreaFunctor: public AbstractViewFunctor {
   protected:
    Window* m_owner = nullptr;
   public:
    DragAreaFunctor() = default;
    DragAreaFunctor(Window* owner);
    ~DragAreaFunctor() = default;

    void operator()() override;
  };
}



#endif /* gui_drag_area_functor.hpp */
