#include "glib_events.hpp"


glib::Event::Event(EventType type): m_type(type) {}


glib::EventType glib::Event::Type() const {
  return m_type;
}


glib::Event::~Event() = default;


glib::MouseButtonEvent::MouseButtonEvent(EventType type): Event(type) {}


glib::MouseButtonEvent::MouseButtonEvent(EventType type, const Vector2u& position):
                        Event(type), m_position(position) {}


glib::MouseButtonEvent::~MouseButtonEvent() = default;


glib::LeftMouseButtonPressedEvent::LeftMouseButtonPressedEvent():
                                   MouseButtonEvent(EventType::LEFT_MOUSE_BUTTON_PRESSED) {}


glib::LeftMouseButtonPressedEvent::LeftMouseButtonPressedEvent(const glib::Vector2u& position):
                                   MouseButtonEvent(EventType::LEFT_MOUSE_BUTTON_PRESSED, position) {}


glib::RightMouseButtonPressedEvent::RightMouseButtonPressedEvent():
                                   MouseButtonEvent(EventType::RIGHT_MOUSE_BUTTON_PRESSED) {}


glib::RightMouseButtonPressedEvent::RightMouseButtonPressedEvent(const glib::Vector2u& position):
                                   MouseButtonEvent(EventType::RIGHT_MOUSE_BUTTON_PRESSED, position) {}


glib::LeftMouseButtonReleasedEvent::LeftMouseButtonReleasedEvent():
                                   MouseButtonEvent(EventType::LEFT_MOUSE_BUTTON_RELEASED) {}


glib::LeftMouseButtonReleasedEvent::LeftMouseButtonReleasedEvent(const glib::Vector2u& position):
                                   MouseButtonEvent(EventType::LEFT_MOUSE_BUTTON_RELEASED, position) {}


glib::RightMouseButtonReleasedEvent::RightMouseButtonReleasedEvent():
                                   MouseButtonEvent(EventType::RIGHT_MOUSE_BUTTON_RELEASED) {}


glib::RightMouseButtonReleasedEvent::RightMouseButtonReleasedEvent(const glib::Vector2u& position):
                                   MouseButtonEvent(EventType::RIGHT_MOUSE_BUTTON_RELEASED, position) {}


glib::CloseSysWindowEvent::CloseSysWindowEvent():
                           Event(glib::EventType::CLOSE_SYS_WINDOW) {}
