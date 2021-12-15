#ifndef GUI_COLOR_SELECT_BUTTON_HPP
#define GUI_COLOR_SELECT_BUTTON_HPP


#include "gui_select_button.hpp"
#include "gui_color_select_button_skin.hpp"
#include "gui_color_select_functor.hpp"


namespace gui {
  class ColorSelectButton: public SelectButton {
   protected:
    glib::ColorRGBA m_color;
   public:
    ColorSelectButton() = default;
    ColorSelectButton(const glib::IntRect& location,
                      ColorSelectButtonSkin* skin,
                      const glib::ColorRGBA& color);
    ~ColorSelectButton() = default;

    void SetColor(const glib::ColorRGBA& color);
    glib::ColorRGBA GetColor() const;

    void SetSkin(AbstractButtonSkin* skin) override;
  };
}


#endif /* gui_color_select_button.hpp */
