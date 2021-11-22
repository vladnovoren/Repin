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


void gui::AbstractView::OnLeftMouseButtonPressed(glib::Vector2i mouse_position) {
  glib::Vector2i mouse_position_inside = mouse_position - m_skin->m_location.m_position;
  m_mouse_press_state = MousePressState::PRESSED;
  for (auto child_it = m_children.begin(); child_it != m_children.end(); ++child_it) {
    auto child_ptr = *child_it;
    if (child_ptr->IsPointInside(mouse_position_inside)) {
      MoveChildUp(child_it);
      child_ptr->OnLeftMouseButtonPressed(mouse_position_inside);
      break;
    }
  }
}


void gui::AbstractView::OnLeftMouseButtonReleased(glib::Vector2i mouse_position) {
  glib::Vector2i mouse_position_inside = mouse_position - m_skin->m_location.m_position;
  m_mouse_press_state = MousePressState::HOVERED;
  if (m_child_under_mouse_pressed != nullptr) {
    m_child_under_mouse_pressed->OnLeftMouseButtonReleased(mouse_position_inside);
  }
}


void gui::AbstractView::OnRightMouseButtonPressed(glib::Vector2i) {
}


void gui::AbstractView::OnRightMouseButtonReleased(glib::Vector2i) {
}


void gui::AbstractView::OnMouseHoverBegin(glib::Vector2i mouse_position) {
  const glib::Vector2i mouse_position_inside = mouse_position - m_skin->m_location.m_position;
  for (auto child_it = m_children.begin(); child_it != m_children.end(); ++child_it) {
    auto child_ptr = *child_it;
    if (child_ptr->IsPointInside(mouse_position_inside)) {
      child_ptr->OnMouseHoverBegin(mouse_position_inside);
      m_child_under_mouse_pressed = child_ptr;
      break;
    }
  }
}


void gui::AbstractView::OnMouseHoverEnd(glib::Vector2i mouse_position) {
  const glib::Vector2i mouse_position_inside = mouse_position - m_skin->m_location.m_position;
  if (m_child_under_mouse_pressed != nullptr) {
    m_child_under_mouse_pressed->OnMouseHoverEnd(mouse_position_inside);
    m_child_under_mouse_pressed = nullptr;
  }
}


void gui::AbstractView::OnMouseMove(glib::Vector2i new_mouse_position) {
  glib::Vector2i new_mouse_position_inside = new_mouse_position - m_skin->m_location.m_position;
  if (!IsPointInside(new_mouse_position)) {
    OnMouseHoverEnd(new_mouse_position_inside);
  } else {
    if (m_child_under_mouse_hovered != nullptr) {
      m_child_under_mouse_hovered->OnMouseMove(new_mouse_position_inside);
      if (m_child_under_mouse_hovered->m_mouse_press_state == MousePressState::IDLE) {
        m_child_under_mouse_hovered = nullptr;
      }
    }
    for (auto child_it = m_children.begin(); child_it != m_children.end(); ++child_it) {
      auto child_ptr = *child_it;
      if (child_ptr->IsPointInside(new_mouse_position_inside)) {
        child_ptr->OnMouseHoverBegin(new_mouse_position_inside);
        m_child_under_mouse_hovered = child_ptr;
      }
    }
  }
  m_curr_mouse_position = new_mouse_position_inside;
}


void gui::AbstractView::OnLeftMouseDrag(glib::Vector2i new_mouse_position) {
  glib::Vector2i new_mouse_position_inside = new_mouse_position - m_skin->m_location.m_position;
  if (m_child_under_mouse_pressed != nullptr) {
    m_child_under_mouse_pressed->OnLeftMouseDrag(new_mouse_position_inside);
    if (m_child_under_mouse_pressed->m_mouse_press_state == MousePressState::IDLE) {
      m_child_under_mouse_pressed = nullptr;
      for (auto child_it = m_children.begin(); child_it != m_children.end(); ++child_it) {
        auto child_ptr = *child_it;
        if (child_ptr->IsPointInside(new_mouse_position_inside)) {
          child_ptr->OnMouseHoverBegin(new_mouse_position_inside);
          m_child_under_mouse_hovered = child_ptr;
        }
      }
    }
  }
  m_curr_mouse_position = new_mouse_position_inside;
}


void gui::AbstractView::OnRightMouseDrag(glib::Vector2i) {}


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


void gui::AbstractView::Move(const glib::Vector2i& delta_position) {
  m_skin->Move(delta_position);
}


void gui::AbstractView::MoveChildUp(std::list<AbstractView*>::iterator child_it) {
  auto child_ptr = *child_it;
  m_children.erase(child_it);
  m_children.push_front(child_ptr);
}
