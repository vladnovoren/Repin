#include "gui_event_emitter.hpp"


gui::EventEmitter& gui::EventEmitter::GetInstance() {
  static EventEmitter instance;
  return instance;
}


gui::EventEmitter::EventEmitter() {
  emitter_funcs[size_t(gui::EventType::CLOSE)]                       = &EventEmitter::EmitClose;
  emitter_funcs[size_t(gui::EventType::LEFT_MOUSE_BUTTON_PRESSED)]   = &EventEmitter::EmitLeftMouseButtonPressed;
  emitter_funcs[size_t(gui::EventType::LEFT_MOUSE_BUTTON_RELEASED)]  = &EventEmitter::EmitLeftMouseButtonReleased;
  emitter_funcs[size_t(gui::EventType::RIGHT_MOUSE_BUTTON_PRESSED)]  = &EventEmitter::EmitRightMouseButtonPressed;
  emitter_funcs[size_t(gui::EventType::RIGHT_MOUSE_BUTTON_RELEASED)] = &EventEmitter::EmitRightMouseButtonReleased;
  emitter_funcs[size_t(gui::EventType::MOUSE_MOVE)]                  = &EventEmitter::EmitMouseMove;
  emitter_funcs[size_t(gui::EventType::LEFT_MOUSE_DRAG)]             = &EventEmitter::EmitLeftMouseDrag;
  emitter_funcs[size_t(gui::EventType::RIGHT_MOUSE_DRAG)]            = &EventEmitter::EmitRightMouseDrag;
}


gui::EventResult gui::EventEmitter::Emit(gui::AbstractEvent* event, AbstractWidget* widget) {
  assert(event != nullptr);
  assert(widget  != nullptr);

  return (this->*emitter_funcs[size_t(event->Type())])(event, widget);
}


gui::EventResult gui::EventEmitter::EmitClose(gui::AbstractEvent* event, AbstractWidget* widget) {
  assert(event != nullptr);
  assert(widget  != nullptr);

  return widget->OnClose();
}


gui::EventResult gui::EventEmitter::EmitLeftMouseButtonPressed(gui::AbstractEvent* event,
                                                   AbstractWidget* widget) {
  assert(event != nullptr);
  assert(widget  != nullptr);

  glib::MouseButtonEvent* mouse_button_event = reinterpret_cast<glib::MouseButtonEvent*>(event);
  return widget->OnLeftMouseButtonPressed(mouse_button_event->m_position);
}


gui::EventResult gui::EventEmitter::EmitLeftMouseButtonReleased(gui::AbstractEvent* event,
                                                    AbstractWidget* widget) {
  assert(event != nullptr);
  assert(widget  != nullptr);

  glib::MouseButtonEvent* mouse_button_event = reinterpret_cast<glib::MouseButtonEvent*>(event);
  return widget->OnLeftMouseButtonReleased(mouse_button_event->m_position);
}


gui::EventResult gui::EventEmitter::EmitRightMouseButtonPressed(gui::AbstractEvent* event,
                                                    AbstractWidget* widget) {
  assert(event != nullptr);
  assert(widget  != nullptr);

  glib::MouseButtonEvent* mouse_button_event = reinterpret_cast<glib::MouseButtonEvent*>(event);
  return widget->OnRightMouseButtonPressed(mouse_button_event->m_position);
}


gui::EventResult gui::EventEmitter::EmitRightMouseButtonReleased(gui::AbstractEvent* event,
                                                     AbstractWidget* widget) {
  assert(event != nullptr);
  assert(widget  != nullptr);

  glib::MouseButtonEvent* mouse_button_event = reinterpret_cast<glib::MouseButtonEvent*>(event);
  return widget->OnRightMouseButtonReleased(mouse_button_event->m_position);
}


gui::EventResult gui::EventEmitter::EmitMouseMove(gui::AbstractEvent* event, AbstractWidget* widget) {
  assert(event != nullptr);
  assert(widget  != nullptr);

  glib::MouseMoveEvent* mouse_move_event = reinterpret_cast<glib::MouseMoveEvent*>(event);
  return widget->OnMouseMove(mouse_move_event->m_new_position);
}


gui::EventResult gui::EventEmitter::EmitLeftMouseDrag(gui::AbstractEvent* event, AbstractWidget* widget) {
  assert(event != nullptr);
  assert(widget  != nullptr);

  glib::MouseMoveEvent* left_mouse_drag = reinterpret_cast<glib::MouseMoveEvent*>(event);
  return widget->OnLeftMouseDrag(left_mouse_drag->m_new_position);
}


gui::EventResult gui::EventEmitter::EmitRightMouseDrag(gui::AbstractEvent* event, AbstractWidget* widget) {
  assert(event != nullptr);
  assert(widget  != nullptr);

  glib::MouseMoveEvent* right_mouse_drag = reinterpret_cast<glib::MouseMoveEvent*>(event);
  return widget->OnRightMouseDrag(right_mouse_drag->m_new_position);
}
