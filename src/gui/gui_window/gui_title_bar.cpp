#include "gui_title_bar.hpp"
#include "gui_view_manager.hpp"


gui::TitleBar::TitleBar(TitleBarSkin* skin):
               m_skin(skin) {
  assert(skin);
}


gui::EventResult gui::TitleBar::OnMouseButtonPressed(glib::Vector2i mouse_position, MouseButton button) {
  if (button == MouseButton::LEFT) {
    m_is_dragging = true;
  }
  m_old_mouse_position = mouse_position;
  ViewManager::GetInstance().AddMouseActiveView(this);
  return EventResult::PROCESSED;
}


gui::EventResult gui::TitleBar::OnMouseMove(glib::Vector2i new_mouse_position) {
  if (m_is_dragging) {
    Move(new_mouse_position - m_old_mouse_position);
  }
  m_old_mouse_position = new_mouse_position;
  return EventResult::PROCESSED;
}


gui::EventResult gui::TitleBar::OnMouseButtonReleased(glib::Vector2i, MouseButton button) {
  if (button == MouseButton::LEFT) {
    m_is_dragging = false;
  }
  ViewManager::GetInstance().RemoveMouseActiveView(this);
  return EventResult::PROCESSED;
}


void gui::TitleBar::Draw(glib::RenderTarget* render_target,
                         const glib::Vector2i& position) {
  assert(render_target != nullptr);

  if (m_needs_to_render) {
    m_skin->Render(m_location.m_size);
    m_needs_to_render = false;
  }
  m_skin->Copy(render_target, position + m_location.m_position);
}


void gui::TitleBar::AddSkin(TitleBarSkin* skin) {
  assert(skin != nullptr);

  m_skin = skin;
}


void gui::TitleBar::AddMinimizeButton(Button* minimize_button) {
  assert(minimize_button != nullptr);

  m_minimize_button = minimize_button;
  m_children.push_front(minimize_button);
}


void gui::TitleBar::AddMaximizeButton(Button* maximize_button) {
  assert(maximize_button != nullptr);

  m_maximize_button = maximize_button;
  m_children.push_front(maximize_button);
}


void gui::TitleBar::AddCloseButton(Button* close_button) {
  assert(close_button != nullptr);

  m_close_button = close_button;
  m_children.push_front(close_button);
}


// void gui::TitleBar::AddTitle(Title* title) {
//   assert(title != nullptr);

//   m_title = title;
//   m_children.push_front(title);
// }
