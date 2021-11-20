#include "glib_texture.hpp"


glib::Texture::Texture(const sf::Texture& sf_texture):
               m_sf_texture(sf_texture) {}


bool glib::Texture::LoadFromFile(const char* file_name) {
  sf::Image sf_image;
  if (!sf_image.loadFromFile(file_name)) {
    return false;
  }
  return true;
}


const sf::Texture& glib::Texture::GetSFMLTexture() const {
  return m_sf_texture;
}


glib::Vector2i glib::Texture::GetSize() const {
  return glib::SFMLToGLibVector2(m_sf_texture.getSize());
}
