#ifndef GUI_TITLE_BAR_SKIN_HPP
#define GUI_TITLE_BAR_SKIN_HPP


#include "gui_abstract_view_skin.hpp"


namespace gui {
  struct TitleBarSkin: AbstractViewSkin {
    glib::Texture       m_texture;
    glib::RenderTexture m_render_texture;
    glib::Texture       m_source_texture;
    glib::IntRect       m_left_location;
    glib::IntRect       m_middle_location;
    glib::IntRect       m_right_location;

    TitleBarSkin() = default;
    TitleBarSkin(const TitleBarSkin& other);
    TitleBarSkin(const glib::Texture& source_texture, const glib::IntRect& left_location,
                 const glib::IntRect& middle_location,
                 const glib::IntRect& right_location);
    ~TitleBarSkin() override = default;

    AbstractViewSkin* Copy() const override;

    void Render(const glib::Vector2i& size);
    void CopyToRenderTarget(glib::RenderTarget* render_target, const glib::Vector2i& position) const;
    bool LoadFromFolder(const char* folder_path) override;
  };
}


#endif /* gui_title_bar_skin.hpp */
