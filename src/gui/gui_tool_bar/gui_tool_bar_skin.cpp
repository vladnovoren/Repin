#include "gui_tool_bar_skin.hpp"


gui::ToolBarSkin::ToolBarSkin(const glib::IntRect& right_edge_location):
                  m_right_edge_location(right_edge_location) {}


gui::ToolBarSkin::ToolBarSkin(const ToolBarSkin& other):
                  AbstractWidgetSkin(other.m_source_texture),
                  m_right_edge_location(other.m_right_edge_location) {}


void gui::ToolBarSkin::Render(glib::Vector2i size) {
  glib::Vector2i texture_size = size;
  texture_size.x += m_right_edge_location.m_size.x / 2;
  m_render_texture.Resize(texture_size);
  m_render_texture.Clear(glib::ColorRGBA(1, 1, 1, 1));

  glib::Vector2i curr_position;
  curr_position.x = size.x - m_right_edge_location.m_size.x / 2;
  for (int i = 0; i < size.y; ++i) {
    m_render_texture.CopyTexture(m_source_texture,
                                 curr_position, m_right_edge_location);
    ++curr_position.y;
  }

  m_render_texture.Display();
  m_texture = m_render_texture.GetTexture();
}


void gui::ToolBarSkin::CopyToRenderTarget(glib::RenderTarget* render_target,
                                          const glib::Vector2i& position) {
  assert(render_target);

  render_target->CopyTexture(m_texture, position);
}
