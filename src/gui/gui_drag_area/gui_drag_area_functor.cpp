#include "gui_drag_area_functor.hpp"
#include "gui_window.hpp"


gui::DragAreaFunctor::DragAreaFunctor(Window* owner): m_owner(owner) {
  assert(owner != nullptr);
}


void gui::DragAreaFunctor::SetDeltaPosition(const glib::Vector2i& delta_position) {
  m_delta_position = delta_position;
}


void gui::DragAreaFunctor::operator()() {
  m_owner->Move(m_delta_position);
}


void gui::DragAreaFunctor::operator()(const glib::Vector2i& delta_position) {
  SetDeltaPosition(delta_position);
  this->operator()();
}
