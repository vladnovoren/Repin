#include "gui_title_bar_skin.hpp"


gui::TitleBarSkin::TitleBarSkin(const glib::Texture& source_texture,
                                const glib::IntRect& left_location,
                                const glib::IntRect& middle_location,
                                const glib::IntRect& right_location):
                   m_source_texture(source_texture),
                   m_left_location(left_location),
                   m_middle_location(middle_location),
                   m_right_location(right_location) {}


gui::TitleBarSkin::TitleBarSkin(const TitleBarSkin& other):
                   m_source_texture(other.m_source_texture),
                   m_left_location(other.m_left_location),
                   m_middle_location(other.m_middle_location),
                   m_right_location(other.m_right_location) {}


void gui::TitleBarSkin::Render(const glib::Vector2i& size) {
  m_render_texture.Resize(size);
  m_render_texture.CopyTexture(m_source_texture, m_left_location.m_position,
                               m_left_location);

  int n_middle = size.x - m_right_location.m_size.x - m_left_location.m_size.x;
  glib::Vector2i curr_position = glib::Vector2i(m_left_location.m_size.x, 0);
  for (int i = 0; i < n_middle; ++i) {
    m_render_texture.CopyTexture(m_source_texture, curr_position, m_middle_location);
    curr_position += glib::Vector2i(1, 0);
  }

  m_render_texture.CopyTexture(m_source_texture, curr_position, m_right_location);
  m_render_texture.Display();
  m_texture = m_render_texture.GetTexture();
}


void gui::TitleBarSkin::CopyToRenderTarget(glib::RenderTarget* render_target,
                             const glib::Vector2i& position) const {
  assert(render_target != nullptr);

  render_target->CopyTexture(m_texture, position);
}


gui::AbstractWidgetSkin* gui::TitleBarSkin::Copy() const {
  return new TitleBarSkin(*this);
}
