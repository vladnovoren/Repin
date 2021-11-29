#include "gui_convert_events_from_glib.hpp"


gui::AbstractEvent* gui::GLibToGUIEvent(const glib::Event* glib_event) {
  assert(glib_event != nullptr);

  switch (glib_event->Type()) {
    case glib::EventType::CLOSE_SYS_WINDOW:
      return new gui::CloseEvent();
    case glib::EventType::LEFT_MOUSE_BUTTON_PRESSED:
    case glib::EventType::LEFT_MOUSE_BUTTON_RELEASED:
    case glib::EventType::RIGHT_MOUSE_BUTTON_PRESSED:
    case glib::EventType::RIGHT_MOUSE_BUTTON_RELEASED:
      return gui::GLibToGUIMouseButtonEvent(glib_event);
    case glib::EventType::MOUSE_MOVE:
    case glib::EventType::LEFT_MOUSE_DRAG:
    case glib::EventType::RIGHT_MOUSE_DRAG:
      return gui::GLibToGUIMouseMoveEvent(glib_event);
    default:
      return nullptr;
  }
}


gui::MouseButtonEvent* gui::GLibToGUIMouseButtonEvent(const glib::Event* glib_event) {
  assert(glib_event != nullptr);

  const glib::MouseButtonEvent* mouse_button_event = reinterpret_cast<const glib::MouseButtonEvent*>(glib_event);
  const glib::Vector2i mouse_position = mouse_button_event->m_position;
  switch (glib_event->Type()) {
    case glib::EventType::LEFT_MOUSE_BUTTON_PRESSED:
      return new gui::LeftMouseButtonPressedEvent(mouse_position);
    case glib::EventType::LEFT_MOUSE_BUTTON_RELEASED:
      return new gui::LeftMouseButtonReleasedEvent(mouse_position);
    case glib::EventType::RIGHT_MOUSE_BUTTON_PRESSED:
      return new gui::RightMouseButtonPressedEvent(mouse_position);
    case glib::EventType::RIGHT_MOUSE_BUTTON_RELEASED:
      return new gui::RightMouseButtonReleasedEvent(mouse_position);
    default:
      return nullptr;
  }
}


gui::MouseMoveEvent* gui::GLibToGUIMouseMoveEvent(const glib::Event* glib_event) {
  assert(glib_event != nullptr);

  const glib::MouseMoveEvent* mouse_move_event = reinterpret_cast<const glib::MouseMoveEvent*>(glib_event);
  const glib::Vector2i new_position = mouse_move_event->m_new_position;
  switch (glib_event->Type()) {
    case glib::EventType::MOUSE_MOVE:
      return new MouseMoveEvent(new_position);
    case glib::EventType::LEFT_MOUSE_DRAG:
      return new LeftMouseDragEvent(new_position);
    case glib::EventType::RIGHT_MOUSE_DRAG:
      return new RightMouseDragEvent(new_position);
    default:
      return nullptr;
  }
}
