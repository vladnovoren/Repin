#include "glib_convert_events.hpp"


glib::Event* glib::SFMLToGLibEvent(const sf::Event& sf_event) {
  switch (sf_event.type) {
    case sf::Event::Closed:
      return new glib::CloseSysWindowEvent();
    case sf::Event::MouseButtonPressed:
    case sf::Event::MouseButtonReleased:
      return glib::SFMLToGLibMouseButtonEvent(sf_event);
    default:
      return nullptr;
  }
}


glib::MouseButtonEvent* glib::SFMLToGLibMouseButtonEvent(const sf::Event& sf_mouse_button_event) {
  glib::Vector2u position(sf_mouse_button_event.mouseButton.x,
                          sf_mouse_button_event.mouseButton.y);
  switch (sf_mouse_button_event.type) {
    case sf::Event::MouseButtonPressed:
      switch (sf_mouse_button_event.mouseButton.button) {
        case sf::Mouse::Button::Left:
          return new glib::LeftMouseButtonPressedEvent(position);
        case sf::Mouse::Button::Right:
          return new glib::RightMouseButtonPressedEvent(position);
        default:
          return nullptr;
      }
    case sf::Event::MouseButtonReleased:
      switch (sf_mouse_button_event.mouseButton.button) {
        case sf::Mouse::Button::Left:
          return new glib::LeftMouseButtonReleasedEvent(position);
        case sf::Mouse::Button::Right:
          return new glib::RightMouseButtonReleasedEvent(position);
        default:
          return nullptr;
      }
    default:
      return nullptr;
  }
}
