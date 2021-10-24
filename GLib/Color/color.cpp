#include "color.hpp"


glib::ColorRGB::ColorRGB() {}


glib::ColorRGB::ColorRGB(double r, double g, double b) {
  this->r = r;
  this->g = g;
  this->b = b;
}


glib::ColorRGB& glib::ColorRGB::operator *= (const double mul) {
  r *= mul;
  g *= mul;
  b *= mul;
  return *this;
}


glib::ColorRGB& glib::ColorRGB::operator *= (const glib::ColorRGB& right) {
  r *= right.r;
  g *= right.g;
  b *= right.b;
  return *this;
}


glib::ColorRGB& glib::ColorRGB::operator += (const glib::ColorRGB& right) {
  r += right.r;
  g += right.g;
  b += right.b;
  return *this;
}


glib::ColorRGB glib::ColorRGB::operator + (const glib::ColorRGB& right) const {
  return ColorRGB(
    r + right.r,
    g + right.g,
    b + right.b
  );
}


glib::ColorRGB glib::ColorRGB::operator * (const glib::ColorRGB& right) const {
  return ColorRGB(
    r * right.r,
    g * right.g,
    b * right.b
  );
}


glib::ColorRGB glib::ColorRGB::operator * (const double scalar) const {
  return ColorRGB(
    r * scalar,
    g * scalar,
    b * scalar
  );
}


glib::ColorRGB glib::operator * (const double scalar, const glib::ColorRGB& color) {
  return ColorRGB(
    scalar * color.r,
    scalar * color.g,
    scalar * color.b
  );
}


tls::Vector2f glib::ToMyVector(const sf::Vector2f& vector) {
  return tls::Vector2f(vector.x, vector.y);
}


template<typename VectorType>
sf::Vector2<VectorType> glib::ToSFMLVector(const tls::Vector2<VectorType>& vector) {
  return sf::Vector2<VectorType>(vector.x, vector.y);
}


sf::Color glib::ToSFMLColor(const ColorRGB& color) {
  return sf::Color(color.r * 255, color.g * 255, color.b * 255, 255);
}
