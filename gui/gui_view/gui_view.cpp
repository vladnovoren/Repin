#include "gui_view.hpp"


gui::View::View(const glib::FloatRect& location): m_location(location) {}


gui::View::~View() = default;


void gui::View::SetLocation(const glib::FloatRect& location) {
  m_location = location;
}


glib::FloatRect gui::View::Location() const {
  return m_location;
}


void gui::View::OnClose() {
  MatchForClose();
  for (auto child_ptr: m_children) {
    child_ptr->OnClose();
  }
}


void gui::View::MatchForClose() {
  m_should_close = true;
}

