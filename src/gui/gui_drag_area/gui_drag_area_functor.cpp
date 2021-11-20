#include "gui_drag_area_functor.hpp"
#include "gui_window.hpp"


gui::DragAreaFunctor::DragAreaFunctor(Window* owner): m_owner(owner) {
  assert(owner != nullptr);
}


void gui::DragAreaFunctor::operator()() {
  // m_owner.
}
