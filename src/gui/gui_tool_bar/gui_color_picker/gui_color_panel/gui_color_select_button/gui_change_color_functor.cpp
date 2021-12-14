#include "gui_change_color_functor.hpp"


void gui::ChangerColorFunctor::operator()() {
  ColorPicker::GetInstance().SetColor(m_color);
}


void gui::ChangeColorFunctor::operator()(const glib::ColorRGBA& color) {
  m_color = color;
  operator()();
}
