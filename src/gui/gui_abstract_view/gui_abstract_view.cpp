#include "gui_abstract_view.hpp"


gui::AbstractView::~AbstractView() {}


void gui::AbstractView::SetLocation(const glib::IntRect& location) {
  m_location = location;
}


glib::IntRect gui::AbstractView::Location() const {
  return m_location;
}


bool gui::AbstractView::IsPointInside(glib::Vector2i point) const {
  return m_location.IsPointInRect(point);
}


gui::EventResult gui::AbstractView::OnMouseButtonPressed(glib::Vector2i, MouseButton) {
  return EventResult::NOT_PROCESSED;
}


gui::EventResult gui::AbstractView::OnMouseButtonReleased(glib::Vector2i, MouseButton) {
  return EventResult::NOT_PROCESSED;
}


gui::EventResult gui::AbstractView::OnMouseHoverBegin(glib::Vector2i) {
  return EventResult::NOT_PROCESSED;
}


gui::EventResult gui::AbstractView::OnMouseHoverEnd(glib::Vector2i) {
  return EventResult::NOT_PROCESSED;
}


gui::EventResult gui::AbstractView::OnMouseMove(glib::Vector2i) {
  return EventResult::NOT_PROCESSED;
}


gui::EventResult gui::AbstractView::OnClose() {
  MatchForClose();
  return EventResult::PROCESSED;
}


void gui::AbstractView::MatchForClose() {
  m_should_close = true;
}


bool gui::AbstractView::ShouldClose() const {
  return m_should_close;
}


void gui::AbstractView::Move(const glib::Vector2i& delta_position) {
  m_location.m_position += delta_position;
}


gui::EventResult gui::AbstractView::OnUnknownEvent() {
  return gui::EventResult::PROCESSED;
}
