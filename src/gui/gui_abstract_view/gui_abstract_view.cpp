#include "gui_abstract_view.hpp"


gui::AbstractView::AbstractView(AbstractViewSkin* skin):
                   m_skin(skin) {}


gui::AbstractView::~AbstractView() = default;


void gui::AbstractView::SetLocation(const glib::UIntRect& location) {
  m_skin->m_location = location;
}


glib::UIntRect gui::AbstractView::Location() const {
  return m_skin->m_location;
}


bool gui::AbstractView::IsPointInside(const glib::Vector2u& point) {
  return m_skin->m_location.IsPointInRect(point);
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
