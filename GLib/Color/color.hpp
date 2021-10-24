#ifndef COLOR_HPP
#define COLOR_HPP

#include "SFML/Graphics.hpp"
#include "tools.hpp"

namespace glib {
  struct ColorRGB {
    double r = 0;
    double g = 0;
    double b = 0;

    ColorRGB();
    ColorRGB(double r, double g, double b);

    ColorRGB& operator *= (const double mul);
    ColorRGB& operator *= (const ColorRGB& right);
    ColorRGB& operator += (const ColorRGB& right);
    ColorRGB operator + (const ColorRGB& right) const;
    ColorRGB operator * (const ColorRGB& right) const;
    ColorRGB operator * (const double scalar) const;
    friend ColorRGB operator * (const double scalar, const ColorRGB& color);
  };

  ColorRGB operator * (const double scalar, const ColorRGB& color);

  sf::Color ToSFMLColor(const ColorRGB& color);

  template<typename VectorType>
  sf::Vector2<VectorType> ToSFMLVector(const tls::Vector2<VectorType>& vector);
  tls::Vector2f ToMyVector(const sf::Vector2f& vector);
}


#endif /* color.hpp */
