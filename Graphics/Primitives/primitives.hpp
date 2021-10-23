#ifndef PRIMITIVES_HPP
#define PRIMITIVES_HPP

#include "color.hpp"


namespace glib {
  struct Primitive {
    ColorRGB color;
  };

  struct Rect: Primitive {
    tls::Vector2f position;
    tls::Vector2f size;

    Rect();
    Rect(const tls::Vector2f& position, const tls::Vector2f& size);

    bool IsPointInRect(const tls::Vector2f& point);
  };


  struct Circle: Primitive {
    tls::Vector2f center;
    double radius;

    Circle();
    Circle(const tls::Vector2f& center, const double radius);
  };


  struct Line: Primitive {
    tls::Vector2f begin;
    tls::Vector2f end;

    Line();
    Line(const tls::Vector2f& begin, const tls::Vector2f& end);
  };
}


#endif /* primitives.hpp */
