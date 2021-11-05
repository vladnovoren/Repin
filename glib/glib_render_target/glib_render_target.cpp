#include "glib_render_target.hpp"
#include "glib_render_texture.hpp"


glib::RenderTarget::RenderTarget(sf::RenderTarget* sf_render_target):
                    m_sf_render_target(sf_render_target) {}


void glib::RenderTarget::RenderLine(const glib::Line& line,
                                    const ColorRGB& color) {
  sf::Vertex sf_line[] = {
    sf::Vertex(glib::GLibToSFMLVector2(line.m_begin), glib::GLibToSFMLColor(color)),
    sf::Vertex(glib::GLibToSFMLVector2(line.m_end), glib::GLibToSFMLColor(color))
  };
  m_sf_render_target->draw(sf_line, 2, sf::Lines);
}


void glib::RenderTarget::RenderRect(const glib::FloatRect& rect,
                                    const ColorRGB& color) {
  sf::RectangleShape sf_rect(glib::GLibToSFMLVector2(rect.m_size));
  sf_rect.setPosition(glib::GLibToSFMLVector2(rect.m_position));
  sf_rect.setFillColor(glib::GLibToSFMLColor(color));
  m_sf_render_target->draw(sf_rect);
}


void glib::RenderTarget::RenderCircle(const glib::Circle& circle,
                                      const ColorRGB& color) {
  sf::CircleShape sf_circle;
  sf_circle.setOrigin(sf::Vector2f(circle.m_radius, circle.m_radius));
  sf_circle.setRadius(circle.m_radius);
  sf_circle.setPosition(circle.m_center.x, circle.m_center.y);
  sf_circle.setFillColor(GLibToSFMLColor(color));
  m_sf_render_target->draw(sf_circle);
}


void glib::RenderTarget::CopyTexture(const Texture& texture,
                                     const Vector2f& position,
                                     const IntRect& texture_rect) {
  sf::Sprite sprite(texture.GetSFMLTexture());
  sprite.setPosition(GLibToSFMLVector2(position));
  sprite.setTextureRect(sf::IntRect(GLibToSFMLVector2(texture_rect.m_position),
                                    GLibToSFMLVector2(texture_rect.m_size)));
  m_sf_render_target->draw(sprite);
}


void glib::RenderTarget::CopyRenderTexture(const RenderTexture& render_texture,
                                           const Vector2f& position,
                                           const IntRect& render_texture_rect) {
  Texture texture(render_texture.GetSFMLRenderTexture().getTexture());
  CopyTexture(texture, position, render_texture_rect);
}
