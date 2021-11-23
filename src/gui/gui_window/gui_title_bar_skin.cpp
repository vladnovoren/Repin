#include "gui_title_bar_skin.hpp"


gui::TitleBarSkin::TitleBarSkin(const glib::IntRect& location,
                                glib::Texture* left_texture,
                                glib::Texture* middle_texture,
                                glib::Texture* right_texture):
                   DefaultViewSkin(location), m_left_texture(left_texture),
                   m_middle_texture(middle_texture),
                   m_right_texture(right_texture) {
  assert(left_texture != nullptr);
  assert(middle_texture != nullptr);
  assert(right_texture != nullptr);
}


void gui::TitleBarSkin::Draw(glib::RenderTarget* render_target,
                             const glib::Vector2i& position) {
  assert(render_target != nullptr);

  render_target->CopyTexture(*m_left_texture, position);
  float left_x = m_left_texture->GetSize().x;
  float step_x = m_middle_texture->GetSize().x;
  glib::Vector2i start_position = position + glib::Vector2i(left_x, 0);
  glib::Vector2i step = glib::Vector2i(step_x, 0);
  size_t n_steps = (m_location.m_size.x - left_x) / step_x;
  for (size_t i = 0; i < n_steps; ++i) {
    glib::Vector2i curr_position = start_position + i * step;
    render_target->CopyTexture(*m_middle_texture, curr_position);
  }
  glib::Vector2i right_position = glib::Vector2i(m_location.m_size.x - m_right_texture->GetSize().x, 0);
  render_target->CopyTexture(*m_right_texture, right_position);
}
