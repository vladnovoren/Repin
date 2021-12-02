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


void gui::Button::Draw(glib::RenderTarget* render_target,
                       const glib::Vector2i&) {
  assert(render_target);

  // m_skin->Draw(render_target, position);
}
//==============================================================================
