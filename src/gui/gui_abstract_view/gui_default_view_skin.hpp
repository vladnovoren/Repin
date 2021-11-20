#ifndef GUI_DEFAULT_VIEW_SKIN_HPP
#define GUI_DEFAULT_VIEW_SKIN_HPP


#include "glib.hpp"


namespace gui {
  struct DefaultViewSkin {
    glib::IntRect m_location;

    DefaultViewSkin() = default;
    DefaultViewSkin(const glib::IntRect& location);
    virtual ~DefaultViewSkin() = default;

    virtual bool IsPointInside(glib::Vector2i point);

    virtual void Draw(glib::RenderTarget* render_target,
                      const glib::Vector2i& position);
  };
};


#endif /* gui_default_view_skin.hpp */
