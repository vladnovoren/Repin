#ifndef RENDER_TEXTURE_HPP
#define RENDER_TEXTURE_HPP

#include "render_target.hpp"


namespace glib {
  class RenderTexture: public RenderTarget {
    private:
      sf::RenderTexture sf_render_texture;
    public:
      RenderTexture();
      RenderTexture(const tls::Vector2f& size);

      void Resize(const tls::Vector2f& size);
      const sf::RenderTexture& GetSFMLRenderTexture() const;
  };
}


#endif /* render_texture.hpp */
