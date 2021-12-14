#include "gui_color_select_button_skin.hpp"


bool gui::ColorSelectButtonSkin::IsPointInside(const glib::IntRect& location,
                                               glib::Vector2i point) const {
  glib::IntRect area_location_to_parent =  m_hit_area;
  area_location_to_parent.m_position    += location.m_position;
  return area_location_to_parent.IsPointInRect(point);
}


void gui::ColorSelectButtonSkin::Render(const glib::ColorRGBA& color) {
  m_render_texture.Resize(m_curr_texture_location.m_size);
  m_render_texture.CopyTexture(m_source_texture, glib::Vector2i(),
                               m_curr_texture_location);
  m_render_texture.RenderRect(m_hit_area, color);
  m_texture = m_render_texture.GetTexture();
}



