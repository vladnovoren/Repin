#include "events.hpp"


glib::MouseButton glib::ToMyMouseButton(sf::Mouse::Button button) {
  switch (button) {
    case sf::Mouse::Button::Left:
      return glib::MouseButton::LEFT;
    case sf::Mouse::Button::Right:
      return glib::MouseButton::RIGHT;
    default:
      return glib::MouseButton::UNDEFINED;
  }
}


glib::Event::EventType ToMyEventType(sf::Event::EventType sf_event_type) {
  switch (sf_event_type) {
    case sf::Event::EventType::MouseButtonPressed:
      return glib::Event::EventType::MOUSE_BUTTON_PRESSED;
    case sf::Event::EventType::MouseButtonReleased:
      return glib::Event::EventType::MOUSE_BUTTON_RELEASED;
    case sf::Event::EventType::Closed:
      return glib::Event::EventType::CLOSED;
    default:
      return glib::Event::EventType::UNDEFINED;
  }
}


glib::Event::MouseButtonEvent ToMyMouseButtonEvent(const sf::Event::MouseButtonEvent& sf_mouse_button_event) {
  glib::Event::MouseButtonEvent mouse_button_event;
  mouse_button_event.button = glib::ToMyMouseButton(sf_mouse_button_event.button);
  mouse_button_event.position = tls::Vector2f(sf_mouse_button_event.x, sf_mouse_button_event.y);
  return mouse_button_event;
}



glib::Event glib::ToMyEvent(const sf::Event& sf_event) {
  glib::Event event = {};
  event.type = ToMyEventType(sf_event.type);
  switch (event.type) {
    case glib::Event::EventType::MOUSE_BUTTON_PRESSED:
    case glib::Event::EventType::MOUSE_BUTTON_RELEASED:
      event.mouse_button = ToMyMouseButtonEvent(sf_event.mouseButton);
      break;
    case glib::Event::EventType::CLOSED:
      break;
    default:
      break;
  }
  return event;
}
