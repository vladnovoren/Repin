#ifndef GUI_CHANGE_COLOR_FUNCTOR_HPP
#define GUI_CHANGE_COLOR_FUNCTOR_HPP


#include "gui_abstract_widget_functor.hpp"
#include "gui_color_picker.hpp"


namespace gui {
  class ChangeColorFunctor: public AbstractWidgetFunctor {
    glib::ColorRGBA color;
   public:
    ~ChangeColorFunctor() = default;

    void operator()() override;
    void operator()(const ColorRGBA& color);
  };
}


#endif /* gui_change_color_functor.hpp */
