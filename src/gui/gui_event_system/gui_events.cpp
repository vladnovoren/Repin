#include "gui_events.hpp"


gui::MouseButton gui::SFMLToGUIMouseButton(sf::Mouse::Button sf_button) {
  switch (sf_button) {
    case sf::Mouse::Button::Left:
      return MouseButton::LEFT;

    case sf::Mouse::Button::Middle:
      return MouseButton::MIDDLE;

    case sf::Mouse::Button::Right:
      return MouseButton::RIGHT;

    default:
      return MouseButton::NO_BUTTON;
  }
}


bool gui::IsMouseEvent(sf::Event sf_event) {
  switch (sf_event.type) {
    case sf::Event::MouseButtonPressed:
    case sf::Event::MouseButtonReleased:
    case sf::Event::MouseMoved:
      return true;
    default:
      return false;
  }
}
