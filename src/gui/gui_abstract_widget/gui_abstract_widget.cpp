#include "gui_abstract_widget.hpp"


gui::AbstractWidget::AbstractWidget(const glib::IntRect& location):
                     m_location(location) {}


gui::AbstractWidget::~AbstractWidget() {}


void gui::AbstractWidget::SetLocation(const glib::IntRect& location) {
  m_location = location;
}


glib::IntRect gui::AbstractWidget::Location() const {
  return m_location;
}


bool gui::AbstractWidget::IsPointInside(glib::Vector2i point) const {
  return m_location.IsPointInRect(point);
}


glib::Vector2i gui::AbstractWidget::PointRelativeToParent(glib::Vector2i point) const {
  AbstractWidget* parent = m_parent_widget;
  while (parent != nullptr) {
    point -= parent->m_location.m_position;
    parent = parent->m_parent_widget;
  }
  return point;
}


gui::EventResult gui::AbstractWidget::OnMouseButtonPressed(glib::Vector2i,
                                                           glib::Vector2i,
                                                           MouseButton) {
  return EventResult::NOT_PROCESSED;
}


gui::EventResult gui::AbstractWidget::OnMouseButtonReleased(glib::Vector2i,
                                                            glib::Vector2i,
                                                            MouseButton) {
  return EventResult::NOT_PROCESSED;
}


gui::EventResult gui::AbstractWidget::OnMouseMove(glib::Vector2i, glib::Vector2i) {
  return EventResult::NOT_PROCESSED;
}


gui::EventResult gui::AbstractWidget::OnClose() {
  MatchForClose();
  return EventResult::PROCESSED;
}


void gui::AbstractWidget::MatchForClose() {
  m_should_close = true;
}


bool gui::AbstractWidget::ShouldClose() const {
  return m_should_close;
}


void gui::AbstractWidget::DeleteMatched() {}


void gui::AbstractWidget::Move(const glib::Vector2i& delta_position) {
  if (m_parent_widget == nullptr) {
    m_location.m_position += delta_position;
  } else {
    glib::Vector2i new_left_up = m_location.m_position + delta_position;
    new_left_up.x = std::max(new_left_up.x, 0);
    new_left_up.y = std::max(new_left_up.y, 0);
    glib::Vector2i new_right_down = new_left_up + m_location.m_size;
    new_right_down.x = std::min(new_right_down.x, m_parent_widget->m_location.m_size.x);
    new_right_down.y = std::min(new_right_down.y, m_parent_widget->m_location.m_size.y);
    m_location.m_position = new_left_up;
  }
}


gui::EventResult gui::AbstractWidget::OnUnknownEvent() {
  return gui::EventResult::PROCESSED;
}
