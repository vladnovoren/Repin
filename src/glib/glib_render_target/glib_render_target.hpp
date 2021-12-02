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
    virtual ~RenderTarget() = 0;

    void Clear(const ColorRGB& color = ColorRGB());

    void RenderLine(const FloatLine& line, const ColorRGB& color);
    void RenderRect(const FloatRect& rect, const ColorRGB& color);
    void RenderCircle(const FloatCircle& circle, const ColorRGB& color);

    void CopyTexture(const Texture& texture, const Vector2f& position,
                     const FloatRect& texture_rect = FloatRect());
    void CopyRenderTexture(const RenderTexture& render_texture,
                           const Vector2f& position,
                           const FloatRect& texture_rect = FloatRect());

    virtual void Display() = 0;
  };
}


#endif /* glib_render_target.hpp */
