#include "gui_title.hpp"


gui::Title::Title(const char* label, const glib::Vector2i& center_position,
                  unsigned int font_size) {
  assert(label != nullptr);

  m_location.m_position = center_position;
}


void gui::Title::SetLabel(const char* label) {
  assert(label != nullptr);

  m_text.SetLabel(label);
  
}
