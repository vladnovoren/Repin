#ifndef GUI_TITLE_BAR_SKIN_HPP
#define GUI_TITLE_BAR_SKIN_HPP


#include "gui_abstract_view_skin.hpp"


namespace gui {
  struct TitleBarSkin: AbstractViewSkin {
    glib::Texture* m_left_texture = nullptr;
    glib::Texture* m_middle_texture = nullptr;
    glib::Texture* m_right_texture = nullptr;

    TitleBarSkin() = default;
    TitleBarSkin(const glib::FloatRect& location, glib::Texture* left_texture,
                 glib::Texture* middle_texture, glib::Texture* right_texture);
    ~TitleBarSkin() override = default;

    void Draw(glib::RenderTarget* render_target, const glib::Vector2f& position);
  };
}


#endif /* gui_title_bar_skin.hpp */
