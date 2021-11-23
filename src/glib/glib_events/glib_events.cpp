#include "glib_events.hpp"


glib::Event::Event(EventType type): m_type(type) {}


glib::EventType glib::Event::Type() const {
  return m_type;
}


glib::Event::~Event() = default;


glib::MouseButtonEvent::MouseButtonEvent(const Vector2i& position):
                        m_position(position) {}


glib::MouseButtonEvent::~MouseButtonEvent() = default;


glib::LeftMouseButtonPressedEvent::LeftMouseButtonPressedEvent():
                                   Event(EventType::LEFT_MOUSE_BUTTON_PRESSED) {}


glib::LeftMouseButtonPressedEvent::LeftMouseButtonPressedEvent(const glib::Vector2i& position):
                                   Event(EventType::LEFT_MOUSE_BUTTON_PRESSED), MouseButtonEvent(position) {}


glib::RightMouseButtonPressedEvent::RightMouseButtonPressedEvent():
                                    Event(EventType::RIGHT_MOUSE_BUTTON_PRESSED) {}


glib::RightMouseButtonPressedEvent::RightMouseButtonPressedEvent(const glib::Vector2i& position):
                                    Event(EventType::RIGHT_MOUSE_BUTTON_PRESSED), MouseButtonEvent(position) {}


glib::LeftMouseButtonReleasedEvent::LeftMouseButtonReleasedEvent():
                                    Event(EventType::LEFT_MOUSE_BUTTON_RELEASED) {}


glib::LeftMouseButtonReleasedEvent::LeftMouseButtonReleasedEvent(const glib::Vector2i& position):
                                    Event(EventType::LEFT_MOUSE_BUTTON_RELEASED), MouseButtonEvent(position) {}


glib::RightMouseButtonReleasedEvent::RightMouseButtonReleasedEvent():
                                     Event(EventType::RIGHT_MOUSE_BUTTON_RELEASED) {}


glib::RightMouseButtonReleasedEvent::RightMouseButtonReleasedEvent(const glib::Vector2i& position):
                                     Event(EventType::RIGHT_MOUSE_BUTTON_RELEASED), MouseButtonEvent(position) {}


glib::CloseSysWindowEvent::CloseSysWindowEvent():
                           Event(EventType::CLOSE_SYS_WINDOW) {}


glib::MouseMoveEvent::MouseMoveEvent():
                      Event(EventType::MOUSE_MOVE) {}


glib::MouseMoveEvent::MouseMoveEvent(const Vector2i& new_position):
                      Event(EventType::MOUSE_MOVE),
                      m_new_position(new_position) {}


glib::LeftMouseDragEvent::LeftMouseDragEvent():
                          Event(EventType::LEFT_MOUSE_DRAG) {}


glib::LeftMouseDragEvent::LeftMouseDragEvent(const Vector2i& new_position):
                          Event(EventType::LEFT_MOUSE_DRAG),
                          MouseMoveEvent(new_position) {}


glib::RightMouseDragEvent::RightMouseDragEvent():
                          Event(EventType::RIGHT_MOUSE_DRAG) {}


glib::RightMouseDragEvent::RightMouseDragEvent(const Vector2i& new_position):
                          Event(EventType::RIGHT_MOUSE_DRAG),
                          MouseMoveEvent(new_position) {}
