#include "glib_primitives.hpp"


template<typename RectType>
glib::Rect<RectType>::Rect(const glib::Vector2<RectType>& position,
                           const glib::Vector2<RectType>& size):
                      m_position(position), m_size(size) {}


template<typename RectType>
bool glib::Rect<RectType>::IsPointInRect(const glib::Vector2<RectType>& point) const {
  return m_position.x < point.x && point.x < m_position.x + m_size.x &&
         m_position.y < point.y && point.y < m_position.y + m_size.y;
}


template<typename RectType>
sf::Rect<RectType> glib::ToSFMLRect(const glib::Rect<RectType>& rect) {
  return sf::Rect<RectType>(glib::GLibToSFMLVector2(rect.m_position),
                            glib::GLibToSFMLVector2(rect.m_size));
}


glib::Circle::Circle(const glib::Vector2f& center, const double radius):
              m_center(center), m_radius(radius) {}


bool glib::Circle::IsPointInside(const glib::Vector2f& point) const {
  return (m_center.x - point.x) * (m_center.x - point.x) +
         (m_center.y - point.y) * (m_center.y - point.y) <=
         m_radius * m_radius;
}
