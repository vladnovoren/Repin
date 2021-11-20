#include "gui_default_view_skin.hpp"


gui::DefaultViewSkin::DefaultViewSkin(const glib::IntRect& location):
                       m_location(location) {}


bool gui::DefaultViewSkin::IsPointInside(glib::Vector2i point) {
  return m_location.IsPointInRect(point);
}


void gui::DefaultViewSkin::Draw(glib::RenderTarget*, const glib::Vector2i&) {}


void gui::DefaultViewSkin::Move(const glib::Vector2i& delta_position) {
  m_location.m_position += delta_position;
}
