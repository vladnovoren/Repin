#ifndef GUI_COLOR_SELECT_BUTTON_HPP
#define GUI_COLOR_SELECT_BUTTON_HPP


#include "gui_abstract_widget.hpp"
#include "gui_color_select_button_skin.hpp"


namespace gui {
  class ColorSelectButton: public AbstractWidget {
   protected:
    glib::ColorRGBA m_color;

    ColorSelectButtonSkin* m_skin = nullptr;
   public:
    ColorSelectButton() = default;
    ColorSelectButton(const glib::IntRect& location,
                      const glib::ColorRGBA& color);
    ~ColorSelectButton();
  };
}


#endif /* gui_color_select_button.hpp */
