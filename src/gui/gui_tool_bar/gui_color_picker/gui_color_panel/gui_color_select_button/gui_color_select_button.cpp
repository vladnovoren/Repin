#include "gui_color_select_button.hpp"


gui::ColorSelectButton::ColorSelectButton(const glib::IntRect& location,
                                          const glib::ColorRGBA& color):
                        AbstractWidget(location), m_color(color) {}


gui::ColorSelectButton::~ColorSelectButton() {
  delete m_skin;
}


void gui::ColorSelectButton::SetSkin(ColorSelectButtonSkin* skin) {
  assert(skin != nullptr);

  delete m_skin;
  m_skin = skin;
}
