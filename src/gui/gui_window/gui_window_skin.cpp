#include "gui_window_skin.hpp"


gui::WindowSkin::WindowSkin(const WindowSkin&) {}


void gui::WindowSkin::Render(const glib::Vector2i& window_size) {
  m_render_texture.Resize(window_size + 2 * WINDOW_SHADOW_SIZE);
  glib::IntRect shadow_rect(glib::Vector2i(),
                            window_size + 2 * WINDOW_SHADOW_SIZE);
  m_render_texture.RenderRect(shadow_rect, glib::ColorRGBA(0, 0, 0, 0.5));
  m_render_texture.Display();
  m_texture = m_render_texture.GetTexture();
}


void gui::WindowSkin::CopyToRenderTarget(glib::RenderTarget* render_target,
                                         const glib::Vector2i& window_position) const {
  assert(render_target != nullptr);

  render_target->CopyRenderTexture(m_render_texture, window_position - glib::Vector2i(WINDOW_SHADOW_THICKNESS, WINDOW_SHADOW_THICKNESS));
}


gui::AbstractWidgetSkin* gui::WindowSkin::Copy() const {
  return new WindowSkin(*this);
}