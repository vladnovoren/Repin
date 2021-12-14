#ifndef GUI_COLOR_PICKER_HPP
#define GUI_COLOR_PICKER_HPP


#include "gui_abstract_container_widget.hpp"
#include "gui_color_picker_skin.hpp"


namespace gui {
  class ColorPicker: public AbstractContainerWidget {
   private:
    ColorPicker();

    glib::ColorRGBA m_curr_color;

    ColorPickerSkin* m_skin = nullptr;
   protected:
    ~ColorPicker() override = default;

    static ColorPicker* GetInstance();

    void SetSkin(ColorPickerSkin* skin);

    void SetColor(const glib::ColorRGBA& color);
    glib::ColorRGBA GetColor() const;
  };
}


#endif /* gui_color_picker.hpp */
