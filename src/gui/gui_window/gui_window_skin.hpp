#ifndef GUI_WINDOW_SKIN_HPP
#define GUI_WINDOW_SKIN_HPP


#include "gui_abstract_widget_skin.hpp"
#include <cstdlib>


namespace gui {
  struct WindowSkin: AbstractWidgetSkin {
    glib::Texture       m_texture;
    glib::RenderTexture m_render_texture;
    glib::Texture       m_source_texture;

    glib::IntRect       m_edge_location;

    WindowSkin() = default;
    WindowSkin(const WindowSkin& other);
    WindowSkin(const glib::Texture& source_texture,
               const glib::IntRect& edge_location);

    void Render(const glib::Vector2i& window_size,
                const glib::Vector2i& title_bar_size);
    void CopyToRenderTarget(glib::RenderTarget* render_target,
                            const glib::Vector2i& position);

    AbstractWidgetSkin* Copy() const override;
  };
}


#endif /* gui_window_skin.hpp */
