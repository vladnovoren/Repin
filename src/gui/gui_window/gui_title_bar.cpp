#include "gui_title_bar.hpp"


gui::TitleBar::TitleBar(TitleBarSkin* skin, Button* minimize_button,
                        Button* maximize_button, Button* close_button,
                        Title* title, gui::Title* title):
               m_skin(skin), m_minimize_button(minimize_button),
               m_maximize_button(maximize_button),
               m_close_button(close_button), m_title(title) {
  assert(skin != nullptr);
}


void gui::TitleBar::Draw(glib::RenderTarget* render_target,
                         const glib::Vector2f& position) {
  assert(render_target != nullptr);

  m_skin->Draw(render_target, position);

  glib::Vector2f curr_position = position - glib::Vector2f(m_skin->m_right_texture->GetSize().x, 0);
  if (m_minimize_button != nullptr) {
    m_minimize_button->Draw(render_target, curr_position);
    curr_position += DELTA_BUTTON;
  }
  if (m_maximize_button != nullptr) {
    m_maximize_button->Draw(render_target, curr_position);
    curr_position += DELTA_BUTTON;
  }
  if (m_close_button != nullptr) {
    m_close_button->Draw(render_target, curr_position);
    curr_position += DELTA_BUTTON;
  }
  if (m_title != nullptr) {
    m_title->Draw(render_target, curr_position);
  }
}
