#ifndef GUI_MAIN_MENU_SKIN_HPP
#define GUI_MAIN_MENU_SKIN_HPP


#include "gui_abstract_widget_skin.hpp"


namespace gui {
  struct MainMenuSkin: AbstractWidgetSkin {
    glib::Texture       m_texture;
    glib::RenderTexture m_render_texture;

    glib::IntRect       m_location;
    glib::Texture       m_source_texture;

    MainMenuSkin() = default;
    MainMenuSkin(const MainMenuSkin& other);
    ~MainMenuSkin() override = default;

    AbstractWidgetSkin* Copy() const override;

    void Render(int length);
    void CopyToRenderTarget(glib::RenderTarget* render_target,
                            const glib::Vector2i& position) const;
  };
}


#endif /* gui_main_menu_skin.hpp */
