#ifndef GUI_VIEW_SKIN_HPP
#define GUI_VIEW_SKIN_HPP


#include "glib.hpp"


namespace gui {
  struct AbstractViewSkin {
    glib::UIntRect m_location;

    AbstractViewSkin() = default;
    AbstractViewSkin(const glib::UIntRect& location);
    virtual ~AbstractViewSkin() = 0;

    virtual bool IsPointInside(glib::Vector2u& point) = 0;

    virtual void Draw(glib::RenderTarget* render_target,
                      const glib::Vector2u& position) = 0;
  };
};


#endif /* gui_abstract_view_skin.hpp */
