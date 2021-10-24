#ifndef PRIMITIVES_HPP
#define PRIMITIVES_HPP

#include "color.hpp"
#include "vector2.hpp"
#include "utils.hpp"


namespace glib {
  template<typename RectType>
  struct Rect {
    tls::Vector2<RectType> position;
    tls::Vector2<RectType> size;

    Rect();
    Rect(const tls::Vector2<RectType>& position, const tls::Vector2<RectType>& size);

    bool IsPointInRect(const tls::Vector2<RectType>& point);
  };

  template<typename RectType>
  sf::Rect<RectType> ToSFMLRect(const Rect<RectType>& rect);

  typedef Rect<float> FloatRect;
  typedef Rect<unsigned int> UIntRect;
  typedef Rect<int> IntRect;


  struct Circle {
    tls::Vector2f center;
    double radius;

    Circle();
    Circle(const tls::Vector2f& center, const double radius);
  };


  struct Line {
    tls::Vector2f begin;
    tls::Vector2f end;

    Line();
    Line(const tls::Vector2f& begin, const tls::Vector2f& end);
  };
}


#endif /* primitives.hpp */
