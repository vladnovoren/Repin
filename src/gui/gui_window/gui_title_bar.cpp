#include "gui_title_bar.hpp"


gui::TitleBar::TitleBar(gui::Button* close_button, gui::Title* title):
               m_close_button(close_button), m_title(title) {
  assert(close_button != nullptr);
  assert(title != nullptr);
}


void gui::TitleBar::Draw(glib::RenderTarget* render_target,
                         const glib::Vector2f& position) {
  assert(render_target != nullptr);

}