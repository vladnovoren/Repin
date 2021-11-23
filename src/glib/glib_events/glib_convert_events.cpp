#include "glib_convert_events.hpp"


glib::Event* glib::SFMLToGLibEvent(const sf::Event& sf_event) {
  switch (sf_event.type) {
    case sf::Event::Closed:
      return new glib::CloseSysWindowEvent();
    case sf::Event::MouseButtonPressed:
    case sf::Event::MouseButtonReleased:
      return glib::SFMLToGLibMouseButtonEvent(sf_event);
    case sf::Event::MouseMoved:
      return glib::SFMLToGLibMouseMoveEvent(sf_event);
    default:
      return nullptr;
  }
}


glib::MouseButtonEvent* glib::SFMLToGLibMouseButtonEvent(const sf::Event& sf_mouse_button_event) {
  glib::Vector2i position(sf_mouse_button_event.mouseButton.x,
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


glib::MouseMoveEvent* glib::SFMLToGLibMouseMoveEvent(const sf::Event& sf_mouse_move_event) {
  const sf::Event::MouseMoveEvent& sf_selected_mouse_move_event = sf_mouse_move_event.mouseMove;
  glib::Vector2i glib_new_position(sf_selected_mouse_move_event.x,
                                   sf_selected_mouse_move_event.y);
  if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
    return new glib::LeftMouseDragEvent(glib_new_position);
  } else if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Right)) {
    return new glib::RightMouseDragEvent(glib_new_position);
  } else {
    return new glib::MouseMoveEvent(glib_new_position);
  }
}
