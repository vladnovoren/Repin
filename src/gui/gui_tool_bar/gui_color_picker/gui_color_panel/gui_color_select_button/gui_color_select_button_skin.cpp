#include "gui_color_select_button_skin.hpp"
#include "gui_color_select_button.hpp"


gui::ColorSelectButtonSkin::ColorSelectButtonSkin(const glib::Texture& source_texture,
                                                  const glib::IntRect& idle_texture_location,
                                                  const glib::IntRect& hovered_texture_location,
                                                  const glib::IntRect& pressed_texture_location,
                                                  const glib::IntRect& hit_area):
                            AbstractButtonSkin(source_texture,
                                               idle_texture_location,
                                               hovered_texture_location,
                                               pressed_texture_location),
                            m_hit_area(hit_area) {}


gui::ColorSelectButtonSkin::ColorSelectButtonSkin(const ColorSelectButtonSkin& other):
                            AbstractButtonSkin(other),
                            m_hit_area(other.m_hit_area) {}


bool gui::ColorSelectButtonSkin::IsPointInside(const glib::IntRect& location,
                                               glib::Vector2i point) const {
  glib::IntRect area_location_to_parent =  m_hit_area;
  area_location_to_parent.m_position    += location.m_position;
  return area_location_to_parent.IsPointInRect(point);
}


void gui::ColorSelectButtonSkin::Render() {
  m_render_texture.Resize(m_curr_texture_location.m_size);
  m_render_texture.Clear(glib::ColorRGBA(0, 0, 0, 0));
  m_render_texture.CopyTexture(m_source_texture, glib::Vector2i(),
                               m_curr_texture_location);

  assert(m_owner != nullptr);
  glib::ColorRGBA color = m_owner->GetColor();
  m_render_texture.RenderRect(m_hit_area, color);
  m_texture = m_render_texture.GetTexture();
}


gui::AbstractButtonSkin* gui::ColorSelectButtonSkin::Copy() const {
  return new ColorSelectButtonSkin(*this);
}
