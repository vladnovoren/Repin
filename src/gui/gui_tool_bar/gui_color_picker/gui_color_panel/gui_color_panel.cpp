#include "gui_color_panel.hpp"


gui::ColorPanel* gui::ColorPanel::GetInstance() {
  static ColorPanel* instance = new ColorPanel;
  return instance;
}


void gui::ColorPanel::AddColorSelectButton(ColorSelectButton* color_select_button) {
  assert(color_select_button != nullptr);

  AddChild(color_select_button);
}
