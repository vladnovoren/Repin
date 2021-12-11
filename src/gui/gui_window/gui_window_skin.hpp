#ifndef GUI_WINDOW_SKIN_HPP
#define GUI_WINDOW_SKIN_HPP


#include "gui_abstract_widget_skin.hpp"
#include "glib.hpp"


namespace gui {
  struct WindowSkin: AbstractWidgetSkin {
    glib::Texture       m_texture;
    glib::RenderTexture m_render_texture;

    WindowSkin() = default;
    WindowSkin(const WindowSkin& other);

    void Render(const glib::Vector2i& window_size);
    void CopyToRenderTarget(glib::RenderTarget* render_target,
                            const glib::Vector2i& window_position) const;
    
    AbstractWidgetSkin* Copy() const override;
  };
}


#endif /* gui_window_skin.hpp */
