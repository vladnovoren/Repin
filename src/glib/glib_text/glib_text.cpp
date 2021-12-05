#include "glib_text.hpp"


glib::Text::Text(const char* label, const Font& font):
            m_sf_text(label, font.GetSFMLFont()) {}


void glib::Text::SetLabel(const char* label) {
  m_sf_text.setString(label);
}


void glib::Text::SetFontSize(unsigned int size) {
  m_sf_text.setCharacterSize(size);
}


void glib::Text::SetColor(const ColorRGBA& color) {
  m_sf_text.setFillColor(GLibToSFMLColor(color));
}


glib::Vector2i glib::Text::GetSize() const {
  sf::FloatRect sf_rect = m_sf_text.getGlobalBounds();
  return glib::Vector2i(sf_rect.width, sf_rect.height);
}


void glib::Text::SetPosition(const Vector2i& position) {
  m_sf_text.setPosition(position.x, position.y);
}


void glib::Text::SetCenterPosition(const Vector2i& center_position) {
  Vector2f left_up_position = center_position - Vector2i(0.5 * GetSize().x, 0);
  SetPosition(left_up_position);
}


void glib::Text::Move(const Vector2i& delta) {
  m_sf_text.move(delta.x, delta.y);
}
