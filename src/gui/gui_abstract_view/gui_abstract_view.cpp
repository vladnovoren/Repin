#include "gui_abstract_view.hpp"


gui::AbstractView::~AbstractView() {}


void gui::AbstractView::SetLocation(const glib::IntRect& location) {
  m_location = location;
}


void gui::AbstractView::SetMousePressState(MousePressState mouse_press_state) {
  SetMousePressState(mouse_press_state);
}


glib::IntRect gui::AbstractView::Location() const {
  return m_location;
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


// bool gui::AbstractView::IsPointInside(const glib::Vector2i& point) {
  // assert(m_skin != nullptr);
// 
  // return m_location.IsPointInRect(point);
// }


void gui::AbstractView::MatchForClose() {
  m_should_close = true;
}


void gui::AbstractView::Move(const glib::Vector2i& delta_position) {
  m_location.m_position += delta_position;
}


gui::EventResult gui::AbstractView::OnUnknownEvent() {
  return gui::EventResult::PROCESSED;
}
