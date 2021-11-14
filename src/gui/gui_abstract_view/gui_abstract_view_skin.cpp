#include "gui_abstract_view_skin.hpp"


gui::AbstractViewSkin::~AbstractViewSkin() = default;


gui::AbstractViewSkin::~AbstractViewSkin(const glib::Vector2u& location):
                       m_location(location) {}
