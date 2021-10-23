#include "texture.hpp"


glib::Texture::Texture() {}


glib::Texture::~Texture() {}


bool glib::Texture::LoadFromFile(const char* file_name) {
  sf::Image sf_image;
  if (!sf_image.loadFromFile(file_name)) {
    return false;
  }
  return true;
}
