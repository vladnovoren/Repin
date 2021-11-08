#ifndef GLIB_RENDER_TEXTURE_HPP
#define GLIB_RENDER_TEXTURE_HPP

#include "glib_render_target.hpp"


namespace glib {
  class RenderTexture: public RenderTarget {
    private:
      sf::RenderTexture m_sf_render_texture;
    public:
      RenderTexture();
      RenderTexture(const Vector2f& size);
      ~RenderTexture() = default;

      void Resize(const Vector2f& size);
      const sf::RenderTexture& GetSFMLRenderTexture() const;
  };
}


#endif /* glib_render_texture.hpp */
