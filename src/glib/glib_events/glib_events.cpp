#include "glib_events.hpp"


glib::Event::Event(EventType type): m_type(type) {}


glib::MouseButtonEvent::MouseButtonEvent(EventType type): m_type(type) {}


glib::MouseButtonEvent::MouseButtonEvent(EventType type, const Vector2f& position):
                        m_type(type), m_position(position) {}


glib::Event::~Event() = default;


glib::MouseButtonEvent::MouseButtonEvent(EventType type): m_type(type) {}


glib::MouseButtonEvent::MouseButtonEvent(glib::EventType type, const glib::Vector2f& position):
                        Event(type), m_position(position) {}


glib::MouseButtonEvent::~MouseButtonEvent() = default;


glib::LeftMouseButtonPressedEvent::LeftMouseButtonPressedEvent():
                                   MouseButtonEvent(EventType::LEFT_MOUSE_BUTTON_PRESSED) {}


glib::LeftMouseButtonPressedEvent::LeftMouseButtonPressedEvent(const glib::Vector2f& position):
                                   MouseButtonEvent(EventType::LEFT_MOUSE_BUTTON_PRESSED, position) {}


glib::RightMouseButtonPressedEvent::RightMouseButtonPressedEvent():
                                   MouseButtonEvent(EventType::RIGHT_MOUSE_BUTTON_PRESSED) {}


glib::RightMouseButtonPressedEvent::RightMouseButtonPressedEvent(const glib::Vector2f& position):
                                   MouseButtonEvent(EventType::RIGHT_MOUSE_BUTTON_PRESSED, position) {}


glib::LeftMouseButtonReleasedEvent::LeftMouseButtonReleasedEvent():
                                   MouseButtonEvent(EventType::LEFT_MOUSE_BUTTON_RELEASED) {}


glib::LeftMouseButtonReleasedEvent::LeftMouseButtonReleasedEvent(const glib::Vector2f& position):
                                   MouseButtonEvent(EventType::LEFT_MOUSE_BUTTON_RELEASED, position) {}


glib::RightMouseButtonReleasedEvent::RightMouseButtonReleasedEvent():
                                   MouseButtonEvent(EventType::RIGHT_MOUSE_BUTTON_RELEASED) {}


glib::RightMouseButtonReleasedEvent::RightMouseButtonReleasedEvent(const glib::Vector2f& position):
                                   MouseButtonEvent(EventType::RIGHT_MOUSE_BUTTON_RELEASED, position) {}


glib::CloseSysWindowEvent::CloseSysWindowEvent():
                           Event(glib::EventType::CLOSE_SYS_WINDOW) {}


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
