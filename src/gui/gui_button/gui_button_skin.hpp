#ifndef GUI_BUTTON_SKIN_HPP
#define GUI_BUTTON_SKIN_HPP


#include "gui_abstract_view_skin.hpp"


namespace gui {
  struct AbstractButtonSkin: AbstractViewSkin {
    glib::Texture* m_curr_texture = nullptr; ///< Pointer to current texture
    glib::Texture* m_idle_texture = nullptr; ///< Texture of idle state
    glib::Texture* m_hovered_texture = nullptr; ///< Texture of hovered state
    glib::Texture* m_pressed_texture = nullptr; ///< Texture of pressed state

    AbstractButtonSkin() = default;
    AbstractButtonSkin(const glib::Vector2f& location,
                       glib::Texture* idle_texture,
                       glib::Texture* hovered_texture,
                       glib::Texture* pressed_texture);
    ~AbstractButtonSkin() override = 0;
  };


  struct RectButtonSkin: AbstractButtonSkin {
    glib::FloatRect m_rect;

    RectButtonSkin() = default;
    RectButtonSkin(const glib::Vector2f& location,
                   glib::Texture* idle_texture,
                   glib::Texture* hovered_texture,
                   glib::Texture* pressed_texture,
                   const glib::FloatRect& rect);
    ~RectButtonSkin() override = default;

    bool IsPointInside(const glib::Vector2f& point) override;

    void Draw(glib::RenderTarget* render_target, const glib::Vector2f& position) override;
  };


  struct CircleButtonSkin: AbstractButtonSkin {
    glib::Circle m_circle;

    CircleButtonSkin() = default;
    CircleButtonSkin(const glib::Vector2f& location,
                     glib::Texture* idle_texture,
                     glib::Texture* hovered_texture,
                     glib::Texture* pressed_texture,
                     const glib::FloatRect& circle);
    ~CircleButtonSkin() override = default;

    bool IsPointInside(const glib::Vector2f& point) override;

    void Draw(glib::RenderTarget* render_target,
              const glib::Vector2f& position) override;
  };
}


#endif /* gui_button_skin.hpp */
