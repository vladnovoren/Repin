#include "gui_default_view_skin.hpp"


gui::DefaultViewSkin::DefaultViewSkin(const glib::IntRect& location):
                       m_location(location) {}


bool gui::DefaultViewSkin::IsPointInside(glib::Vector2i point) {
  return m_location.IsPointInRect(point);
}


void gui::DefaultViewSkin::Draw(glib::RenderTarget*, const glib::Vector2i&) {}
