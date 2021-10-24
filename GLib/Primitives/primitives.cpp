#include "primitives.hpp"


template<typename RectType>
glib::Rect<RectType>::Rect() {}


template<typename RectType>
glib::Rect<RectType>::Rect(const tls::Vector2<RectType>& position,
                 const tls::Vector2<RectType>& size):
            position(position), size(size) {}


template<typename RectType>
bool glib::Rect<RectType>::IsPointInRect(const tls::Vector2<RectType>& point) {
  return position.x < point.x && point.x < position.x + size.x &&
         position.y < point.y && point.y < position.y + size.y;
}


template<typename RectType>
sf::Rect<RectType> glib::ToSFMLRect(const glib::Rect<RectType>& rect) {
  return sf::Rect<RectType>(glib::ToSFMLVector(rect.position),
                            glib::ToSFMLVector(rect.size));
}