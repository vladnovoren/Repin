#include "glib_events.hpp"


glib::Event::~Event() {}


glib::MouseButtonEvent::MouseButtonEvent(const glib::MouseButton button,
                                         const glib::Vector2f& position):
                        m_button(button), m_position(position) {}


glib::MouseButtonEvent::~MouseButtonEvent() {}


void glib::MouseButtonEvent::SetType(const glib::MouseButton button) {
  m_button = button;
}


void glib::MouseButtonEvent::SetPosition(const glib::Vector2f& position) {
  m_position = position;
}


glib::MouseButton glib::MouseButtonEvent::Button() const {
  return m_button;
}


glib::Vector2f glib::MouseButtonEvent::Position() const {
  return m_position;
}


glib::MouseButtonPressedEvent::MouseButtonPressedEvent(const MouseButton button,
                                                       const glib::Vector2f& position):
                               MouseButtonEvent(button, position) {}


glib::MouseButtonReleasedEvent::MouseButtonReleasedEvent(const MouseButton button,
                                                         const glib::Vector2f& position):
                                MouseButtonEvent(button, position) {}


glib::MouseButton glib::SFMLToGLibMouseButton(const sf::Mouse::Button sf_button) {
  switch (sf_button) {
    case sf::Mouse::Button::Left:
      return MouseButton::LEFT;
    case sf::Mouse::Button::Right:
      return MouseButton::RIGHT;
    default:
      return MouseButton::LEFT;
  }
}


glib::MouseButtonEvent* glib::SFMLToGLibMouseButtonEvent(const sf::Event& sf_event) {
  MouseButton button = SFMLToGLibMouseButton(sf_event.mouseButton.button);
  Vector2f position(sf_event.mouseButton.x, sf_event.mouseButton.y);
  switch (sf_event.type) {
    case sf::Event::MouseButtonPressed:
    case sf::Event::MouseButtonReleased:
      return new MouseButtonPressedEvent(button, position);
    default:
      return nullptr;
  }
  return nullptr;
}


glib::Event* glib::SFMLToGLibEvent(const sf::Event& sf_event) {
  switch (sf_event.type) {
    case sf::Event::EventType::Closed:
      return new CloseSysWindowEvent();
    case sf::Event::EventType::MouseButtonPressed:
    case sf::Event::EventType::MouseButtonReleased:
      return SFMLToGLibMouseButtonEvent(sf_event);
    default:
      return nullptr;
  }
  return nullptr;
}
