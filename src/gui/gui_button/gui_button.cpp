#include "gui_button.hpp"


// Button
//==============================================================================
gui::Button::Button(AbstractViewFunctor* functor, AbstractButtonSkin* skin):
             m_functor(functor), m_skin(skin) {
  assert(functor != nullptr);
  assert(skin    != nullptr);
}


void gui::Button::SetSkin(AbstractButtonSkin* skin) {
  assert(skin);

  m_skin = skin;
}


void gui::Button::SetFunctor(AbstractViewFunctor* functor) {
  assert(functor);

  m_functor = functor;
}


void gui::Button::SetMousePressState(MousePressState mouse_press_state) {
  AbstractView::SetMousePressState(mouse_press_state);
  switch (mouse_press_state) {
    case MousePressState::IDLE:
      m_skin->m_curr_texture_location = m_skin->m_idle_texture_location;
      break;
    case MousePressState::HOVERED:
      m_skin->m_curr_texture_location = m_skin->m_hovered_texture_location;
      break;
    case MousePressState::LEFT_PRESSED:
      m_skin->m_curr_texture_location = m_skin->m_pressed_texture_location;
      break;
    default:
      break;
  }
}


void gui::Button::Draw(glib::RenderTarget* render_target,
                       const glib::Vector2i&) {
  assert(render_target);

  // m_skin->Draw(render_target, position);
}
//==============================================================================
