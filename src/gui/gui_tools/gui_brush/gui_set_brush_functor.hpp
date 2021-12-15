#ifndef GUI_SET_BRUSH_FUNCTOR_HPP
#define GUI_SET_BRUSH_FUNCTOR_HPP


#include "gui_abstract_widget_functor.hpp"
#include "gui_tool_bar.hpp"


namespace gui {
  class SetBrushFunctor: public AbstractWidgetFunctor {
   public:
    ~SetBrushFunctor() override = default;

    void operator()() override;
  };
}


#endif /* gui_set_brush_functor.hpp */
