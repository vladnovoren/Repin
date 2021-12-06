#ifndef GUI_BUTTON_SKIN_HPP
#define GUI_BUTTON_SKIN_HPP


#include "gui_abstract_widget_skin.hpp"


namespace gui {
  struct AbstractButtonSkin: AbstractWidgetSkin {
    glib::RenderTexture m_render_texture;
    glib::Texture       m_texture;

    glib::Texture       m_source_texture;
    glib::IntRect       m_curr_texture_location;
    glib::IntRect       m_idle_texture_location;
    glib::IntRect       m_hovered_texture_location;
    glib::IntRect       m_pressed_texture_location;

    AbstractButtonSkin() = default;
    AbstractButtonSkin(const AbstractButtonSkin& other);
    AbstractButtonSkin(const glib::Texture& source_texture,
                       const glib::IntRect& idle_texture_location,
                       const glib::IntRect& hovered_texture_location,
                       const glib::IntRect& pressed_texture_location);
    ~AbstractButtonSkin() override = 0;

    virtual bool IsPointInside(const glib::IntRect& location,
                               glib::Vector2i point) const = 0;

    void Render(const glib::Vector2i& size);
    void CopyToRenderTarget(glib::RenderTarget* render_target,
              const glib::Vector2i& position) const;

    void SetIdle();
    void SetHovered();
    void SetPressed();
  };


  struct RectButtonSkin: AbstractButtonSkin {
    RectButtonSkin() = default;
    RectButtonSkin(const glib::Texture& source_texture,
                   const glib::IntRect& idle_texture_location,
                   const glib::IntRect& hovered_texture_location,
                   const glib::IntRect& pressed_texture_location);
    ~RectButtonSkin() override = default;

    bool IsPointInside(const glib::IntRect& location,
                       glib::Vector2i point) const override;

    AbstractWidgetSkin* Copy() const override;
  };


  struct CircleButtonSkin: AbstractButtonSkin {
    CircleButtonSkin() = default;
    CircleButtonSkin(const glib::Texture& source_texture,
                     const glib::IntRect& idle_texture_location,
                     const glib::IntRect& hovered_texture_location,
                     const glib::IntRect& pressed_texture_location);
    ~CircleButtonSkin() override = default;

    bool IsPointInside(const glib::IntRect& location,
                       glib::Vector2i point) const override;

    AbstractWidgetSkin* Copy() const override;
  };
}


#endif /* gui_button_skin.hpp */
