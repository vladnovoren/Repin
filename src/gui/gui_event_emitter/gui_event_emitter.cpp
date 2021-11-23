#include "gui_event_emitter.hpp"


gui::EventEmitter::EventEmitter() {
  emitter_funcs[size_t(glib::EventType::CLOSE_SYS_WINDOW)]            = &EventEmitter::EmitClose;
  emitter_funcs[size_t(glib::EventType::LEFT_MOUSE_BUTTON_PRESSED)]   = &EventEmitter::EmitLeftMouseButtonPressed;
  emitter_funcs[size_t(glib::EventType::LEFT_MOUSE_BUTTON_RELEASED)]  = &EventEmitter::EmitLeftMouseButtonReleased;
  emitter_funcs[size_t(glib::EventType::RIGHT_MOUSE_BUTTON_PRESSED)]  = &EventEmitter::EmitRightMouseButtonPressed;
  emitter_funcs[size_t(glib::EventType::RIGHT_MOUSE_BUTTON_RELEASED)] = &EventEmitter::EmitRightMouseButtonReleased;
  emitter_funcs[size_t(glib::EventType::MOUSE_MOVE)]                  = &EventEmitter::EmitMouseMove;
  emitter_funcs[size_t(glib::EventType::LEFT_MOUSE_DRAG)]             = &EventEmitter::EmitLeftMouseDrag;
  emitter_funcs[size_t(glib::EventType::RIGHT_MOUSE_DRAG)]            = &EventEmitter::EmitRightMouseDrag;
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

  glib::MouseButtonEvent* mouse_button_event = reinterpret_cast<glib::MouseButtonEvent*>(event);
  view->OnLeftMouseButtonPressed(mouse_button_event->m_position);
}


void gui::EventEmitter::EmitLeftMouseButtonReleased(glib::Event* event,
                                                    AbstractView* view) {
  assert(event != nullptr);
  assert(view  != nullptr);

  glib::MouseButtonEvent* mouse_button_event = reinterpret_cast<glib::MouseButtonEvent*>(event);
  view->OnLeftMouseButtonReleased(mouse_button_event->m_position);
}


void gui::EventEmitter::EmitRightMouseButtonPressed(glib::Event* event,
                                                    AbstractView* view) {
  assert(event != nullptr);
  assert(view  != nullptr);

  glib::MouseButtonEvent* mouse_button_event = reinterpret_cast<glib::MouseButtonEvent*>(event);
  view->OnRightMouseButtonPressed(mouse_button_event->m_position);
}


void gui::EventEmitter::EmitRightMouseButtonReleased(glib::Event* event,
                                                     AbstractView* view) {
  assert(event != nullptr);
  assert(view  != nullptr);

  glib::MouseButtonEvent* mouse_button_event = reinterpret_cast<glib::MouseButtonEvent*>(event);
  view->OnRightMouseButtonReleased(mouse_button_event->m_position);
}


void gui::EventEmitter::EmitMouseMove(glib::Event* event, AbstractView* view) {
  assert(event != nullptr);
  assert(view  != nullptr);

  glib::MouseMoveEvent* mouse_move_event = reinterpret_cast<glib::MouseMoveEvent*>(event);
  view->OnMouseMove(mouse_move_event->m_new_position);
}


void gui::EventEmitter::EmitLeftMouseDrag(glib::Event* event, AbstractView* view) {
  assert(event != nullptr);
  assert(view  != nullptr);

  glib::MouseMoveEvent* left_mouse_drag = reinterpret_cast<glib::MouseMoveEvent*>(event);
  view->OnLeftMouseDrag(left_mouse_drag->m_new_position);
}


void gui::EventEmitter::EmitRightMouseDrag(glib::Event* event, AbstractView* view) {
  assert(event != nullptr);
  assert(view  != nullptr);

  glib::MouseMoveEvent* right_mouse_drag = reinterpret_cast<glib::MouseMoveEvent*>(event);
  view->OnRightMouseDrag(right_mouse_drag->m_new_position);
}
