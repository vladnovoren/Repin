#include "texture.hpp"


glib::Texture::Texture() {}


glib::Texture::Texture(const sf::Texture& sf_texture): sf_texture(sf_texture) {}


glib::Texture::~Texture() {}


bool glib::Texture::LoadFromFile(const char* file_name) {
  sf::Image sf_image;
  if (!sf_image.loadFromFile(file_name)) {
    return false;
  }
  return true;
}


const sf::Texture& glib::Texture::GetSFMLTexture() const {
  return sf_texture;
}