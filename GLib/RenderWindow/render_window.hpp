#ifndef RENDER_WINDOW_HPP
#define RENDER_WINDOW_HPP

#include "events.hpp"
#include "render_target.hpp"


namespace glib {
  class RenderWindow: public RenderTarget {
    sf::RenderWindow sf_render_window;
  public:
    RenderWindow();
    RenderWindow(const tls::Vector2f& size, const char* title);
    ~RenderWindow() override;

    void Resize(const tls::Vector2f& size);

    bool ShouldClose();
    void Display();
    double ResetTime();

    bool PollEvent(Event* event);
  };
}


#endif /* render_window.hpp */
