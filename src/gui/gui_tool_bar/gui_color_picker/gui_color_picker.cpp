#include "gui_color_picker.hpp"


gui::ColorPicker::ColorPicker() {
  // AddChild()
}


gui::ColorPicker* gui::ColorPicker::GetInstance() {
  static ColorPicker* instance = new ColorPicker;
  return instance;
}


void gui::ColorPicker::SetSkin(ColorPickerSkin* skin) {
  assert(skin != nullptr);

  m_skin = skin;
}


void gui::ColorPicker::SetColor(const glib::ColorRGBA& color) {
  m_curr_color = color;
}


glib::ColorRGBA gui::ColorPicker::GetColor() const {
  return m_curr_color;
}

