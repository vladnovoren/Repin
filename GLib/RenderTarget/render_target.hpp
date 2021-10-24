#ifndef RENDER_TARGET_HPP
#define RENDER_TARGET_HPP

#include "SFML/Graphics.hpp"
#include "primitives.hpp"
#include "texture.hpp"


namespace glib {
  class RenderTexture;

  class RenderTarget {
    sf::RenderTarget* sf_render_target;
  public:
    RenderTarget();
    RenderTarget(sf::RenderTarget* sf_render_target);
    virtual ~RenderTarget();

    void Clear(const ColorRGB& color);

    void RenderLine(const Line& line, const ColorRGB& color);
    void RenderRect(const FloatRect& rect, const ColorRGB& color);
    void RenderCircle(const Circle& circle, const ColorRGB& color);

    void CopyTexture(const Texture& texture, const tls::Vector2f& position,
                     const IntRect& texture_rect);
    void CopyRenderTexture(const RenderTexture& render_texture,
                           const tls::Vector2f& position,
                           const IntRect& texture_rect);
  };
}


#endif /* render_target.hpp */
