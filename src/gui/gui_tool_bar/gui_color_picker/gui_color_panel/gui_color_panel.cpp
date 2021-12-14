#include "gui_color_panel.hpp"


gui::ColorPanel::~ColorPanel() {
  delete m_skin;
}


gui::ColorPanel* gui::ColorPanel::GetInstance() {
  static ColorPanel* instance = new ColorPanel;
  return instance;
}
