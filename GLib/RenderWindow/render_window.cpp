#include "render_window.hpp"


glib::RenderWindow::RenderWindow():
                    RenderTarget(&sf_render_window) {
}


glib::RenderWindow::RenderWindow(const tls::Vector2f& size, const char* title):
                    RenderTarget(&sf_render_window) {
  sf_render_window.create(sf::VideoMode(size.x, size.y), title);
  sf_render_window.setVerticalSyncEnabled(true);
}


glib::RenderWindow::~RenderWindow() {
  sf_render_window.close();
}


void glib::RenderWindow::Resize(const tls::Vector2f& size) {
  sf_render_window.setSize(sf::Vector2u(size.x, size.y));
}


bool glib::RenderWindow::PollEvent(Event* event) {
  assert(event);

  sf::Event sf_event;
  if (sf_render_window.pollEvent(sf_event)) {
    *event = ToMyEvent(sf_event);
    return true;
  }
  return false;
}
