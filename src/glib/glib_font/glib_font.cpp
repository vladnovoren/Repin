#include "glib_font.hpp"


glib::Font::Font(const sf::Font& sf_font):
            m_sf_font(sf_font) {}


bool glib::Font::LoadFromFile(const char* file_path) {
  assert(file_path != nullptr);

  return m_sf_font.loadFromFile(file_path);
}
