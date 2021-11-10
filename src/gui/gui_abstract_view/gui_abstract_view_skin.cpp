#include "gui_abstract_view_skin.hpp"


gui::AbstractViewSkin::~AbstractViewSkin() = default;


gui::AbstractViewSkin::~AbstractViewSkin(const glib::Vector2f& location):
                       m_location(location) {}
