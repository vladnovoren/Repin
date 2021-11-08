#ifndef GLIB_TEXTURE_HPP
#define GLIB_TEXTURE_HPP


#include "SFML/Graphics.hpp"


namespace glib {
  class Texture {
    sf::Texture m_sf_texture;
   public:
    Texture() = default;
    Texture(const sf::Texture& sf_texture);
    ~Texture() = default;

    bool LoadFromFile(const char* file_name);
    const sf::Texture& GetSFMLTexture() const;
  };
}


#endif /* glib_texture.hpp */
