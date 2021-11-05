#include "gui_events.hpp"


gui::Event::~Event() = default;


void gui::CloseEvent::Process(View* view) {
  view->OnClose();
}


gui::MouseButtonPressedEvent::MouseButtonPressedEvent(glib::MouseButtonPressedEvent* sf_mouse_button_pressed_event):
                              MouseButtonEvent(sf_mouse_button_pressed_event) {}


gui::MouseButtonReleasedEvent::MouseButtonReleasedEvent(glib::MouseButtonReleasedEvent* sf_mouse_button_released_event):
                              MouseButtonEvent(sf_mouse_button_released_event) {}


void gui::MouseButtonPressedEvent::Process(View* view) {
  switch (m_sf_mouse_button_event->Button()) {
    case glib::MouseButton::LEFT:
      view->OnLeftMouseButtonPressed();
      break;
    case glib::MouseButton::RIGHT:
      view->OnRightMouseButtonPressed();
      break;
  }
}


void gui::MouseButtonReleasedEvent::Process(View* view) {
  switch (m_sf_mouse_button_event->Button()) {
    case glib::MouseButton::LEFT:
      view->OnLeftMouseButtonReleased();
      break;
    case glib::MouseButton::RIGHT:
      view->OnRightMouseButtonReleased();
      break;
  }
}