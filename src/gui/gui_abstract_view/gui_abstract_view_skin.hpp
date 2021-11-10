#ifndef GUI_VIEW_SKIN_HPP
#define GUI_VIEW_SKIN_HPP


#include "glib.hpp"


namespace gui {
  struct AbstractViewSkin {
    glib::FloatRect m_location;

    AbstractViewSkin() = default;
    AbstractViewSkin(const glib::Vector2f& location);
    virtual ~AbstractViewSkin() = 0;

    virtual bool IsPointInside(const glib::Vector2f& point) = 0;

    virtual void Draw(glib::RenderTarget* render_target,
                      const glib::Vector2f& position) = 0;
  };
};


#endif /* gui_abstract_view_skin.hpp */
