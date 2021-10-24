#include "render_texture.hpp"


glib::RenderTexture::RenderTexture():
                     RenderTarget(&sf_render_texture) {}


glib::RenderTexture::RenderTexture(const tls::Vector2f& size):
                     RenderTarget(&sf_render_texture) {
  sf_render_texture.create(size.x, size.y);
}


void glib::RenderTexture::Resize(const tls::Vector2f& size) {
  sf_render_texture.create(size.x, size.y);
}


const sf::RenderTexture& glib::RenderTexture::GetSFMLRenderTexture() const {
  return sf_render_texture;
}