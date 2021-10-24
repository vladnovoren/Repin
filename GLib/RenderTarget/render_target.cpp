#include "render_target.hpp"
#include "render_texture.hpp"


glib::RenderTarget::RenderTarget() {}


glib::RenderTarget::RenderTarget(sf::RenderTarget* sf_render_target):
                    sf_render_target(sf_render_target) {}


glib::RenderTarget::~RenderTarget() {}


void glib::RenderTarget::RenderLine(const glib::Line& line,
                                    const ColorRGB& color) {
  sf::Vertex sf_line[] = {
    sf::Vertex(ToSFMLVector(line.begin), ToSFMLColor(color)),
    sf::Vertex(ToSFMLVector(line.end), ToSFMLColor(color))
  };
  sf_render_target->draw(sf_line, 2, sf::Lines);
}


void glib::RenderTarget::RenderRect(const glib::FloatRect& rect,
                                    const ColorRGB& color) {
  sf::RectangleShape sf_rect(ToSFMLVector(rect.size));
  sf_rect.setPosition(ToSFMLVector(rect.position));
  sf_rect.setFillColor(ToSFMLColor(color));
  sf_render_target->draw(sf_rect);
}


void glib::RenderTarget::RenderCircle(const glib::Circle& circle,
                                      const ColorRGB& color) {
  sf::CircleShape sf_circle;
  sf_circle.setOrigin(sf::Vector2f(circle.radius, circle.radius));
  sf_circle.setRadius(circle.radius);
  sf_circle.setPosition(circle.center.x, circle.center.y);
  sf_circle.setFillColor(ToSFMLColor(color));
  sf_render_target->draw(sf_circle);
}


void glib::RenderTarget::CopyTexture(const Texture& texture,
                                     const tls::Vector2f& position,
                                     const IntRect& texture_rect) {
  sf::Sprite sprite(texture.GetSFMLTexture());
  sprite.setPosition(ToSFMLVector(position));
  sprite.setTextureRect(sf::IntRect(ToSFMLVector(texture_rect.position),
                                    ToSFMLVector(texture_rect.size)));
  sf_render_target->draw(sprite);
}


void glib::RenderTarget::CopyRenderTexture(const RenderTexture& render_texture,
                                           const tls::Vector2f& position,
                                           const IntRect& render_texture_rect) {
  Texture texture(render_texture.GetSFMLRenderTexture().getTexture());
  CopyTexture(texture, position, render_texture_rect);
}
