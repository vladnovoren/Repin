#ifndef GLIB_PRIMITIVES_HPP
#define GLIB_PRIMITIVES_HPP


#include "glib_color.hpp"
#include "glib_tools.hpp"


namespace glib {
  template<typename RectType>
  struct Rect {
    Vector2<RectType> m_position;
    Vector2<RectType> m_size;

    Rect() = default;
    Rect(const Vector2<RectType>& position, const Vector2<RectType>& size);
    Rect(const Rect& other) = default;

    bool IsPointInRect(const Vector2<RectType>& point) const;

    Rect& operator=(const Rect& other) {
      m_position = other.m_position;
      m_size = other.m_size;
      return *this;
    }
  };

  template<typename RectType>
  sf::Rect<RectType> ToSFMLRect(const Rect<RectType>& rect);

  typedef Rect<float> FloatRect;
  typedef Rect<unsigned int> UIntRect;
  typedef Rect<int> IntRect;


  struct Circle {
    Vector2f m_center;
    double   m_radius;

    Circle() = default;
    Circle(const Vector2f& center, const double radius);

    bool IsPointInside(const Vector2f& point) const;
  };


  struct Line {
    Vector2f m_begin;
    Vector2f m_end;

    Line() = default;
    Line(const Vector2f& begin, const Vector2f& end);
  };
}


#endif /* glib_primitives.hpp */
