#ifndef RENDER_TARGET_HPP
#define RENDER_TARGET_HPP

#include "SFML/Graphics.hpp"
#include "primitives.hpp"
#include "graphics.hpp"


namespace glib {
  class RenderTarget {
    sf::RenderTarget* sf_render_target;
  public:
    RenderTarget();
    RenderTarget(sf::RenderTarget* sf_render_target);
    virtual ~RenderTarget();

    void Clear(const ColorRGB& color);

    void RenderLine(const Line& line);
    void RenderRect(const Rect& rect);
    void RenderCircle(const Circle& circle);
  };
}


#endif /* render_target.hpp */
