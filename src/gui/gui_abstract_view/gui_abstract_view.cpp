#include "gui_abstract_view.hpp"


gui::AbstractView::AbstractView(DefaultViewSkin* skin):
                   m_skin(skin) {}


gui::AbstractView::~AbstractView() = default;


void gui::AbstractView::SetLocation(const glib::IntRect& location) {
  m_skin->m_location = location;
}


glib::IntRect gui::AbstractView::Location() const {
  return m_skin->m_location;
}


bool gui::AbstractView::IsPointInside(const glib::Vector2i& point) {
  return m_skin->m_location.IsPointInRect(point);
}


void gui::AbstractView::OnLeftMouseButtonPressed(glib::Vector2i) {
}


void gui::AbstractView::OnRightMouseButtonPressed(glib::Vector2i) {
}


void gui::AbstractView::OnLeftMouseButtonReleased(glib::Vector2i) {
}


void gui::AbstractView::OnRightMouseButtonReleased(glib::Vector2i) {
}


void gui::AbstractView::OnMouseHoverBegin(glib::Vector2i mouse_position) {
  const glib::Vector2i mouse_position_inside = mouse_position - m_skin->m_location.m_position;
  for (auto child = m_children.begin(); child != m_children.end(); ++child) {
    if ((*child)->IsPointInside(mouse_position_inside)) {
      m_child_under_mouse = *child;
      (*child)->OnMouseHoverBegin(mouse_position_inside);
      break;
    }
  }
}


void gui::AbstractView::OnMouseHoverEnd(glib::Vector2i mouse_position) {
  const glib::Vector2i mouse_position_inside = mouse_position - m_skin->m_location.m_position;
  if (m_child_under_mouse != nullptr) {
    m_child_under_mouse->OnMouseHoverEnd(mouse_position_inside);
  }
}


void gui::AbstractView::OnMouseMove(glib::Vector2i new_mouse_position) {
  glib::Vector2i new_mouse_position_inside = new_mouse_position - m_skin->m_location.m_position;
  if (m_child_under_mouse != nullptr) {
    for (auto child: m_children) {
      if (!child->m_skin->IsPointInside(new_mouse_position_inside) &&
          child == m_child_under_mouse) {
        child->OnMouseHoverEnd(new_mouse_position_inside);
        m_child_under_mouse = nullptr;
        break;
      }
    }
  }

  for (auto child: m_children) {
    if (child->m_skin->IsPointInside(new_mouse_position_inside)) {
      child->OnMouseMove(new_mouse_position_inside);
    }
  }

  if (m_child_under_mouse == nullptr) {
    OnMouseHoverBegin(new_mouse_position);
  }
}


void gui::AbstractView::OnClose() {
  MatchForClose();
  for (auto child_ptr: m_children) {
    child_ptr->OnClose();
  }
}


void gui::AbstractView::MatchForClose() {
  m_should_close = true;
}


void gui::AbstractView::Draw(glib::RenderTarget*, const glib::Vector2i&) {}
