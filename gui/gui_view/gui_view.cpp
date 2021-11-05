#include "gui_view.hpp"


gui::View::View(const glib::FloatRect& location): m_location(location) {}


gui::View::~View() = default;


void gui::View::SetLocation(const glib::FloatRect& location) {
  m_location = location;
}


glib::FloatRect gui::View::Location() const {
  return m_location;
}