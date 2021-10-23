#include "render_target.hpp"


glib::RenderTarget::RenderTarget() {}


glib::RenderTarget::RenderTarget(sf::RenderTarget* sf_render_target):
                    sf_render_target(sf_render_target) {}


glib::RenderTarget::~RenderTarget() {}


void glib::RenderTarget::RenderLine(const glib::Line& line) {
  sf::Vertex sf_line[] = {
    sf::Vertex(ToSFMLVector(line.begin), ToSFMLColor(line.color)),
    sf::Vertex(ToSFMLVector(line.end), ToSFMLColor(line.color))
  };
  sf_render_target->draw(sf_line, 2, sf::Lines);
}


void glib::RenderTarget::RenderRect(const glib::Rect& rect) {
  sf::RectangleShape sf_rect(ToSFMLVector(rect.size));
  sf_rect.setPosition(ToSFMLVector(rect.position));
  sf_rect.setFillColor(ToSFMLColor(rect.color));
  sf_render_target->draw(sf_rect);
}


void glib::RenderTarget::RenderCircle(const glib::Circle& circle) {
  sf::CircleShape sf_circle;
  sf_circle.setOrigin(sf::Vector2f(circle.radius, circle.radius));
  sf_circle.setRadius(circle.radius);
  sf_circle.setPosition(circle.center.x, circle.center.y);
  sf_circle.setFillColor(ToSFMLColor(circle.color));
  sf_render_target->draw(sf_circle);
}
