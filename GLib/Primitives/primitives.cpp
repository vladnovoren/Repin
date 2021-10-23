#include "primitives.hpp"


glib::Rect::Rect() {}


glib::Rect::Rect(const tls::Vector2f& position, const tls::Vector2f& size):
            position(position), size(size) {}


bool glib::Rect::IsPointInRect(const tls::Vector2f& point) {
  return position.x < point.x && point.x < position.x + size.x &&
         position.y < point.y && point.y < position.y + size.y;
}


glib::Circle::Circle() {}


glib::Circle::Circle(const tls::Vector2f& center, const double radius):
              center(center), radius(radius) {}


glib::Line::Line() {}


glib::Line::Line(const tls::Vector2f& begin, const tls::Vector2f& end):
            begin(begin), end(end) {}