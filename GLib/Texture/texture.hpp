#ifndef TEXTURE_HPP
#define TEXTURE_HPP

#include "SFML/Graphics.hpp"


namespace glib {
  class Texture {
    sf::Texture sf_texture;
  public:
    Texture();
    Texture(const sf::Texture& sf_texture);
    ~Texture();

    bool LoadFromFile(const char* file_name);
    const sf::Texture& GetSFMLTexture() const;
  };
}


#endif /* texture.hpp */