#ifndef GLIB_RENDER_WINDOW_HPP
#define GLIB_RENDER_WINDOW_HPP

#include "glib_convert_events.hpp"
#include "glib_render_target.hpp"


namespace glib {
  class RenderWindow: public RenderTarget {
    sf::RenderWindow m_sf_render_window;
    sf::Clock m_sf_clock;
  public:
    RenderWindow() = default;
    RenderWindow(const Vector2f& size, const char* title);
    ~RenderWindow() override;

    void Resize(const Vector2f& size);

    void Display();
    double ResetTime();

    bool PollEvent(sf::Event* sf_event);

    const sf::RenderWindow* GetSFMLRenderWindow();
  };
}


#endif /* glib_render_window.hpp */
