#include "glib_render_texture.hpp"


glib::RenderTexture::RenderTexture():
                     RenderTarget(&m_sf_render_texture) {}


glib::RenderTexture::RenderTexture(const Vector2f& size):
                     RenderTarget(&m_sf_render_texture) {
  m_sf_render_texture.create(size.x, size.y);
}


void glib::RenderTexture::Resize(const Vector2f& size) {
  m_sf_render_texture.create(size.x, size.y);
}


const sf::RenderTexture& glib::RenderTexture::GetSFMLRenderTexture() const {
  return m_sf_render_texture;
}