#include "gui_color_select_button.hpp"


gui::ColorSelectButton::ColorSelectButton(const glib::IntRect& location,
                                          ColorSelectButtonSkin* skin,
                                          const glib::ColorRGBA& color):
                        SelectButton(location, skin) {
  SetColor(color);
  skin->m_owner = this;
}


void gui::ColorSelectButton::SetColor(const glib::ColorRGBA& color) {
  m_color = color;
  delete m_functor;
  ColorSelectFunctor* functor = new ColorSelectFunctor(color);
  m_functor = functor;
}


glib::ColorRGBA gui::ColorSelectButton::GetColor() const {
  return m_color;
}


void gui::ColorSelectButton::SetSkin(AbstractButtonSkin* skin) {
  ColorSelectButtonSkin* casted_skin = dynamic_cast<ColorSelectButtonSkin*>(skin);
  if (casted_skin == nullptr) {
    printf("invalid skin!\n");
    return;
  }
  AbstractButton::SetSkin(casted_skin);
  ColorSelectButtonSkin* m_casted_skin = dynamic_cast<ColorSelectButtonSkin*>(m_skin);
  m_casted_skin->m_owner = this;
}
