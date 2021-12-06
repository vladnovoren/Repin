#include "gui_window_skin.hpp"


gui::WindowSkin::WindowSkin(const WindowSkin& other):
                 m_source_texture(other.m_source_texture),
                 m_edge_location(other.m_edge_location) {}


void gui::WindowSkin::Render(const glib::Vector2i& window_size,
                             const glib::Vector2i& title_bar_size) {
  m_render_texture.Resize(window_size);

  glib::Vector2i curr_position(0, title_bar_size.y);
  glib::Vector2i content_size(window_size.x, window_size.y - title_bar_size.y);

  for (int i = 0; i < content_size.y; ++i) {
    m_render_texture.CopyTexture(m_source_texture, curr_position, m_edge_location);
    ++curr_position.y;
  }
  --curr_position.y;
  for (int i = 0; i < content_size.x; ++i) {
    m_render_texture.CopyTexture(m_source_texture, curr_position, m_edge_location);
    ++curr_position.x;
  }
  --curr_position.x;
  for (int i = 0; i < content_size.y; ++i) {
    m_render_texture.CopyTexture(m_source_texture, curr_position, m_edge_location);
    --curr_position.y;
  }

  m_render_texture.Display();
  m_texture = m_render_texture.GetTexture();
}


void gui::WindowSkin::CopyToRenderTarget(glib::RenderTarget* render_target,
                                         const glib::Vector2i& position) {
  assert(render_target != nullptr);

  render_target->CopyTexture(m_texture, position);
}


gui::AbstractWidgetSkin* gui::WindowSkin::Copy() const {
  return new WindowSkin(*this);
}
