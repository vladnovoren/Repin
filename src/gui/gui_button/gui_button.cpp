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


void gui::Button::OnLeftMouseButtonPressed(glib::Vector2i) {
  m_press_state = gui::ButtonPressState::PRESSED;
  m_skin->m_curr_texture = m_skin->m_pressed_texture;
  return m_functor->operator()();
}


void gui::Button::OnLeftMouseButtonReleased(glib::Vector2i) {
  m_press_state = gui::ButtonPressState::IDLE;
  m_skin->m_curr_texture = m_skin->m_idle_texture;
}


void gui::Button::Draw(glib::RenderTarget* render_target,
                       const glib::Vector2i& position) {
  assert(render_target);

  m_skin->Draw(render_target, position);
}
//==============================================================================
