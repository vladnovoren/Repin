#include "gui_event_emitter.hpp"


gui::EventEmitter::EventEmitter() {
  emitter_funcs[size_t(glib::EventType::CLOSE_SYS_WINDOW)]            = &EventEmitter::EmitClose;
  emitter_funcs[size_t(glib::EventType::LEFT_MOUSE_BUTTON_PRESSED)]   = &EventEmitter::EmitLeftMouseButtonPressed;
  emitter_funcs[size_t(glib::EventType::LEFT_MOUSE_BUTTON_RELEASED)]  = &EventEmitter::EmitLeftMouseButtonReleased;
  emitter_funcs[size_t(glib::EventType::RIGHT_MOUSE_BUTTON_PRESSED)]  = &EventEmitter::EmitRightMouseButtonPressed;
  emitter_funcs[size_t(glib::EventType::RIGHT_MOUSE_BUTTON_RELEASED)] = &EventEmitter::EmitRightMouseButtonReleased;
}


void gui::EventEmitter::Emit(glib::Event* event, AbstractView* view) {
  assert(event != nullptr);
  assert(view  != nullptr);

  (this->*emitter_funcs[size_t(event->Type())])(event, view);
}


void gui::EventEmitter::EmitClose(glib::Event* event, AbstractView* view) {
  assert(event != nullptr);
  assert(view  != nullptr);

  view->OnClose();
}


void gui::EventEmitter::EmitLeftMouseButtonPressed(glib::Event* event,
                                                   AbstractView* view) {
  assert(event != nullptr);
  assert(view  != nullptr);

  glib::MouseButtonEvent* mouse_button_event = static_cast<glib::MouseButtonEvent*>(event);
  view->OnLeftMouseButtonPressed(mouse_button_event->m_position);
}


void gui::EventEmitter::EmitLeftMouseButtonReleased(glib::Event* event,
                                                    AbstractView* view) {
  assert(event != nullptr);
  assert(view  != nullptr);

  glib::MouseButtonEvent* mouse_button_event = static_cast<glib::MouseButtonEvent*>(event);
  view->OnLeftMouseButtonReleased(mouse_button_event->m_position);
}


void gui::EventEmitter::EmitRightMouseButtonPressed(glib::Event* event,
                                                    AbstractView* view) {
  assert(event != nullptr);
  assert(view  != nullptr);

  glib::MouseButtonEvent* mouse_button_event = static_cast<glib::MouseButtonEvent*>(event);
  view->OnRightMouseButtonPressed(mouse_button_event->m_position);
}


void gui::EventEmitter::EmitRightMouseButtonReleased(glib::Event* event,
                                                     AbstractView* view) {
  assert(event != nullptr);
  assert(view  != nullptr);

  glib::MouseButtonEvent* mouse_button_event = static_cast<glib::MouseButtonEvent*>(event);
  view->OnRightMouseButtonReleased(mouse_button_event->m_position);
}
