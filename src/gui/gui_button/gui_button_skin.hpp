#ifndef GUI_BUTTON_SKIN_HPP
#define GUI_BUTTON_SKIN_HPP


#include "gui_abstract_view_skin.hpp"


namespace gui {
  struct AbstractButtonSkin: AbstractViewSkin {
    glib::Texture m_texture;

    glib::IntRect m_curr_texture_location;
    glib::IntRect m_idle_texture_location;
    glib::IntRect m_hovered_texture_location;
    glib::IntRect m_pressed_texture_location;

    AbstractButtonSkin() = default;
    AbstractButtonSkin(const glib::Texture& texture,
                       const glib::IntRect& idle_texture_location,
                       const glib::IntRect& hovered_texture_location,
                       const glib::IntRect& pressed_texture_location);
    ~AbstractButtonSkin() override = 0;

    bool LoadFromFolder(const char* folder_path) override;
  };


  struct RectButtonSkin: AbstractButtonSkin {
    RectButtonSkin() = default;
    RectButtonSkin(const glib::Texture& texture,
                   const glib::IntRect& idle_texture_location,
                   const glib::IntRect& hovered_texture_location,
                   const glib::IntRect& pressed_texture_location);
    ~RectButtonSkin() override = default;
  };


  struct CircleButtonSkin: AbstractButtonSkin {
    CircleButtonSkin() = default;
    CircleButtonSkin(const glib::Texture& texture,
                     const glib::IntRect& idle_texture,
                     const glib::IntRect& hovered_texture,
                     const glib::IntRect& pressed_texture);
    ~CircleButtonSkin() override = default;
  };
}


#endif /* gui_button_skin.hpp */
