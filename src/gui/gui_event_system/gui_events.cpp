#include "gui_events.hpp"


gui::AbstractEvent::AbstractEvent(EventType type): m_type(type) {}


gui::EventType gui::AbstractEvent::Type() const {
  return m_type;
}


gui::AbstractEvent::~AbstractEvent() = default;


gui::MouseButtonEvent::MouseButtonEvent(const glib::Vector2i& position):
                       m_position(position) {}


gui::MouseButtonEvent::~MouseButtonEvent() = default;


gui::LeftMouseButtonPressedEvent::LeftMouseButtonPressedEvent() {
  m_type = EventType::LEFT_MOUSE_BUTTON_PRESSED;
}


gui::LeftMouseButtonPressedEvent::LeftMouseButtonPressedEvent(const glib::Vector2i& position):
                                  MouseButtonEvent(position) {
  m_type = EventType::LEFT_MOUSE_BUTTON_PRESSED;
}


gui::RightMouseButtonPressedEvent::RightMouseButtonPressedEvent() {
  m_type = EventType::RIGHT_MOUSE_BUTTON_PRESSED;
}


gui::RightMouseButtonPressedEvent::RightMouseButtonPressedEvent(const glib::Vector2i& position):
                                   MouseButtonEvent(position) {
  m_type = EventType::RIGHT_MOUSE_BUTTON_PRESSED;
}


gui::LeftMouseButtonReleasedEvent::LeftMouseButtonReleasedEvent() {
  m_type = EventType::LEFT_MOUSE_BUTTON_RELEASED;
}


gui::LeftMouseButtonReleasedEvent::LeftMouseButtonReleasedEvent(const glib::Vector2i& position):
                                   MouseButtonEvent(position) {
  m_type = EventType::LEFT_MOUSE_BUTTON_RELEASED;
}


gui::RightMouseButtonReleasedEvent::RightMouseButtonReleasedEvent() {
  m_type = EventType::RIGHT_MOUSE_BUTTON_RELEASED;
}


gui::RightMouseButtonReleasedEvent::RightMouseButtonReleasedEvent(const glib::Vector2i& position):
                                    MouseButtonEvent(position) {
  m_type = EventType::RIGHT_MOUSE_BUTTON_RELEASED;
}


gui::CloseEvent::CloseEvent() {
  m_type = EventType::CLOSE;
}


gui::MouseMoveEvent::MouseMoveEvent() {
  m_type = EventType::MOUSE_MOVE;
}


gui::MouseMoveEvent::MouseMoveEvent(const glib::Vector2i& new_position):
                     m_new_position(new_position) {
  m_type = EventType::MOUSE_MOVE;
}


gui::LeftMouseDragEvent::LeftMouseDragEvent() {
  m_type = EventType::LEFT_MOUSE_DRAG;
}


gui::LeftMouseDragEvent::LeftMouseDragEvent(const glib::Vector2i& new_position):
                         MouseMoveEvent(new_position) {
  m_type = EventType::LEFT_MOUSE_DRAG;
}


gui::RightMouseDragEvent::RightMouseDragEvent() {
  m_type = EventType::RIGHT_MOUSE_DRAG;
}


gui::RightMouseDragEvent::RightMouseDragEvent(const glib::Vector2i& new_position):
                          MouseMoveEvent(new_position) {
  m_type = EventType::RIGHT_MOUSE_DRAG;
}
