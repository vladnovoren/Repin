#ifndef GUI_BUTTON_SKIN_HPP
#define GUI_BUTTON_SKIN_HPP


#include "gui_default_view_skin.hpp"


namespace gui {
  struct AbstractButtonSkin: DefaultViewSkin {
    const glib::Texture* m_curr_texture    = nullptr; ///< Pointer to current texture
    const glib::Texture* m_idle_texture    = nullptr; ///< Texture of idle state
    const glib::Texture* m_hovered_texture = nullptr; ///< Texture of hovered state
    const glib::Texture* m_pressed_texture = nullptr; ///< Texture of pressed state

    AbstractButtonSkin() = default;
    AbstractButtonSkin(const glib::IntRect& location,
                       const glib::Texture* idle_texture,
                       const glib::Texture* hovered_texture,
                       const glib::Texture* pressed_texture);
    ~AbstractButtonSkin() override = 0;
  };


  struct RectButtonSkin: AbstractButtonSkin {
    RectButtonSkin() = default;
    RectButtonSkin(const glib::IntRect& location,
                   const glib::Texture* idle_texture,
                   const glib::Texture* hovered_texture,
                   const glib::Texture* pressed_texture);
    ~RectButtonSkin() override = default;

    bool IsPointInside(glib::Vector2i point) override;

    void Draw(glib::RenderTarget* render_target, const glib::Vector2i& position) override;
  };


  struct CircleButtonSkin: AbstractButtonSkin {
    glib::UIntCircle m_circle;

    CircleButtonSkin() = default;
    CircleButtonSkin(const glib::IntRect& location,
                     const glib::Texture* idle_texture,
                     const glib::Texture* hovered_texture,
                     const glib::Texture* pressed_texture,
                     const glib::UIntCircle& circle);
    ~CircleButtonSkin() override = default;

    bool IsPointInside(glib::Vector2i point) override;

    void Draw(glib::RenderTarget* render_target,
              const glib::Vector2i& position) override;
  };
}


#endif /* gui_button_skin.hpp */
