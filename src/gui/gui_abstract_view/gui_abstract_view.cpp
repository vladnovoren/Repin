#include "gui_abstract_view.hpp"


gui::AbstractView::AbstractView(const glib::FloatRect& location):
                   m_location(location) {}


gui::AbstractView::~AbstractView() = default;


void gui::AbstractView::SetLocation(const glib::FloatRect& location) {
  m_location = location;
}


glib::FloatRect gui::AbstractView::Location() const {
  return m_location;
}


gui::EventResult gui::AbstractView::OnClose() {
  MatchForClose();
  for (auto child_ptr: m_children) {
    child_ptr->OnClose();
  }
  return EventResult::PROCESSED_ALL;
}


void gui::AbstractView::MatchForClose() {
  m_should_close = true;
}
