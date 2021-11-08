#ifndef GLIB_RENDER_TARGET_HPP
#define GLIB_RENDER_TARGET_HPP


#include "SFML/Graphics.hpp"
#include "glib_primitives.hpp"
#include "glib_texture.hpp"


namespace glib {
  class RenderTexture;

  class RenderTarget {
    sf::RenderTarget* m_sf_render_target;
  public:
    RenderTarget() = default;
    RenderTarget(sf::RenderTarget* sf_render_target);
    virtual ~RenderTarget() = default;

    void Clear(const ColorRGB& color);

    void RenderLine(const Line& line, const ColorRGB& color);
    void RenderRect(const FloatRect& rect, const ColorRGB& color);
    void RenderCircle(const Circle& circle, const ColorRGB& color);

    void CopyTexture(const Texture& texture, const Vector2f& position,
                     const IntRect& texture_rect);
    void CopyRenderTexture(const RenderTexture& render_texture,
                           const Vector2f& position,
                           const IntRect& texture_rect);
  };
}


#endif /* glib_render_target.hpp */
