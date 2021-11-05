#include "glib_primitives.hpp"


template<typename RectType>
glib::Rect<RectType>::Rect(const glib::Vector2<RectType>& position,
                           const glib::Vector2<RectType>& size):
                      m_position(position), m_size(size) {}


template<typename RectType>
bool glib::Rect<RectType>::IsPointInRect(const glib::Vector2<RectType>& point) {
  return m_position.x < point.x && point.x < m_position.x + m_size.x &&
         m_position.y < point.y && point.y < m_position.y + m_size.y;
}


template<typename RectType>
sf::Rect<RectType> glib::ToSFMLRect(const glib::Rect<RectType>& rect) {
  return sf::Rect<RectType>(glib::GLibToSFMLVector2(rect.m_position),
                            glib::GLibToSFMLVector2(rect.m_size));
}