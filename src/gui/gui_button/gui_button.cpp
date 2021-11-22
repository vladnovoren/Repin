#include "gui_button.hpp"


// Button
//==============================================================================
gui::Button::Button(AbstractViewFunctor* functor, AbstractButtonSkin* skin):
             m_functor(functor), m_skin(skin) {
  assert(functor);
  assert(skin);
}


gui::Button::~Button() = default;


void gui::Button::SetSkin(AbstractButtonSkin* skin) {
  assert(skin);

  m_skin = skin;
}


void gui::Button::SetFunctor(AbstractViewFunctor* functor) {
  assert(functor);

  m_functor = functor;
}


void gui::Button::SetMousePressState(MousePressState mouse_press_state) {
  m_mouse_press_state = mouse_press_state;
  switch (mouse_press_state) {
    case MousePressState::IDLE:
      m_skin->m_curr_texture = m_skin->m_idle_texture;
      break;
    case MousePressState::HOVERED:
      m_skin->m_curr_texture = m_skin->m_hovered_texture;
      break;
    case MousePressState::PRESSED:
      m_skin->m_curr_texture = m_skin->m_pressed_texture;
      break;
  }
}


void gui::Button::OnMouseHoverBegin(glib::Vector2i) {
  SetMousePressState(MousePressState::HOVERED);
}


void gui::Button::OnMouseHoverEnd(glib::Vector2i) {
  SetMousePressState(MousePressState::IDLE);
}


void gui::Button::OnMouseMove(glib::Vector2i new_mouse_position) {
  glib::Vector2i new_mouse_position_inside = new_mouse_position - m_skin->m_location.m_position;
  if (!IsPointInside(new_mouse_position)) {
    OnMouseHoverEnd(new_mouse_position_inside);
  }
  m_curr_mouse_position = new_mouse_position_inside;
}


void gui::Button::OnLeftMouseDrag(glib::Vector2i new_mouse_position) {
  glib::Vector2i new_mouse_position_inside = new_mouse_position - m_skin->m_location.m_position;
  if (!IsPointInside(new_mouse_position)) {
    OnMouseHoverEnd(new_mouse_position_inside);
  }
  m_curr_mouse_position = new_mouse_position_inside;
}


void gui::Button::OnRightMouseDrag(glib::Vector2i new_mouse_position) {}


void gui::Button::OnLeftMouseButtonPressed(glib::Vector2i) {
  SetMousePressState(MousePressState::PRESSED);
}


void gui::Button::OnLeftMouseButtonReleased(glib::Vector2i) {
  m_functor->operator()();
  SetMousePressState(MousePressState::IDLE);
}


void gui::Button::Draw(glib::RenderTarget* render_target,
                       const glib::Vector2i& position) {
  assert(render_target);

  m_skin->Draw(render_target, position);
}
//==============================================================================
