#include "gui_title_bar.hpp"


gui::TitleBar::TitleBar(TitleBarSkin* skin, Button* minimize_button,
                        Button* maximize_button, Button* close_button,
                        Title* title):
               m_skin(skin), m_minimize_button(minimize_button),
               m_maximize_button(maximize_button),
               m_close_button(close_button), m_title(title) {
  assert(skin != nullptr);
}


void gui::TitleBar::Draw(glib::RenderTarget* render_target,
                         const glib::Vector2i& position) {
  assert(render_target != nullptr);

  m_skin->Draw(render_target, position);

  glib::Vector2i curr_position = position + glib::Vector2i(m_skin->m_right_texture->GetSize().x, 0);
  if (m_close_button != nullptr) {
    m_close_button->Draw(render_target, curr_position);
    curr_position += DELTA_BUTTON;
  }
  if (m_maximize_button != nullptr) {
    m_maximize_button->Draw(render_target, curr_position);
    curr_position += DELTA_BUTTON;
  }
  if (m_minimize_button != nullptr) {
    m_minimize_button->Draw(render_target, curr_position);
    curr_position += DELTA_BUTTON;
  }
  if (m_title != nullptr) {
    m_title->Draw(render_target, curr_position);
  }
}


void gui::TitleBar::OnMouseMove(glib::Vector2i new_mouse_position) {
  glib::Vector2i new_mouse_position_inside = new_mouse_position - m_skin->m_location.m_position;

  // Разобрались с тем, что было в предыдущем фрейме
  if (m_child_under_mouse != nullptr) {
    bool is_point_inside = m_child_under_mouse->IsPointInside(new_mouse_position_inside);
    if (m_is_mouse_pressed || is_point_inside) {
      m_child_under_mouse->OnMouseMove(new_mouse_position_inside);
      return;
    } else if (!is_point_inside) {
      m_child_under_mouse->OnMouseHoverEnd(new_mouse_position_inside);
      m_child_under_mouse = nullptr;
    }
  } else {
  }
}


void gui::TitleBar::OnLeftMouseButtonPressed(glib::Vector2i mouse_position) {
  m_is_mouse_pressed = true;
  glib::Vector2i new_mouse_position_inside = mouse_position - m_skin->m_location.m_position;
  for (auto child_it = m_children.begin(); child_it != m_children.end(); ++child_it) {
    auto child_ptr = *child_it;
    if (child_ptr->IsPointInside(new_mouse_position_inside)) {
      child_ptr->OnLeftMouseButtonPressed(new_mouse_position_inside);
      m_child_under_mouse = child_ptr;
    }
  }
}


void gui::TitleBar::OnLeftMouseButtonReleased(glib::Vector2i mouse_position) {
  m_is_mouse_pressed  = false;
  m_child_under_mouse = nullptr;
  glib::Vector2i new_mouse_position_inside = mouse_position - m_skin->m_location.m_position;
  for (auto child_it = m_children.begin(); child_it != m_children.end(); ++child_it) {
    auto child_ptr = *child_it;
    if (child_ptr->IsPointInside(new_mouse_position_inside)) {
      child_ptr->OnLeftMouseButtonReleased(new_mouse_position_inside);
    }
  }
}
