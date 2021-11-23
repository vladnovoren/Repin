#ifndef GUI_TITLE_BAR_SKIN_HPP
#define GUI_TITLE_BAR_SKIN_HPP


#include "gui_default_view_skin.hpp"


namespace gui {
  struct TitleBarSkin: DefaultViewSkin {
    glib::Texture* m_left_texture = nullptr;
    glib::Texture* m_middle_texture = nullptr;
    glib::Texture* m_right_texture = nullptr;

    TitleBarSkin() = default;
    TitleBarSkin(const glib::IntRect& location, glib::Texture* left_texture,
                 glib::Texture* middle_texture, glib::Texture* right_texture);
    ~TitleBarSkin() override = default;

    void Draw(glib::RenderTarget* render_target, const glib::Vector2i& position);
  };
}


#endif /* gui_title_bar_skin.hpp */
