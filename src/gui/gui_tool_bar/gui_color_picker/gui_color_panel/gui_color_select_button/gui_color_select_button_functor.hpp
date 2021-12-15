#ifndef GUI_COLOR_SELECT_BUTTON_FUNCTOR_HPP
#define GUI_COLOR_SELECT_BUTTON_FUNCTOR_HPP


#include "gui_color_select_functor.hpp"
#include "gui_color_panel.hpp"


namespace gui {
  class ColorSelectButton;

  class ColorSelectButtonFunctor: public ColorSelectFunctor {
   protected:
    ColorSelectButton* m_owner = nullptr;
   public:
    ColorSelectButtonFunctor() = default;
    ColorSelectButtonFunctor(ColorSelectButton* owner,
                             const glib::ColorRGBA& color);
    ~ColorSelectButtonFunctor() = default;

    void operator()() override;
    void operator()(ColorSelectButton* owner, const glib::ColorRGBA& color);

    void SetOwner(ColorSelectButton* owner);
  };
}


#endif /* gui_color_select_button_functor.hpp */
