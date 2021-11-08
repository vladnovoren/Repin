#include "gui_button.hpp"


// AbstractButton
//==============================================================================
gui::AbstractButton::AbstractButton(const glib::FloatRect& location,
                                    glib::Texture* idle_texture,
                                    glib::Texture* hovered_texture,
                                    glib::Texture* pressed_texture):
                     AbstractView(location), m_curr_texture(idle_texture),
                     m_idle_texture(idle_texture),
                     m_hovered_texture(hovered_texture),
                     m_pressed_texture(pressed_texture) {}


void gui::AbstractButton::SetSkin(glib::Texture* idle_texture,
                                  glib::Texture* hovered_texture,
                                  glib::Texture* pressed_texture) {
  m_idle_texture    = idle_texture;
  m_hovered_texture = hovered_texture;
  m_pressed_texture = pressed_texture;
}
//==============================================================================


// RectButton
//==============================================================================
gui::RectButton::RectButton(const glib::FloatRect& location,
                            glib::Texture* idle_texture,
                            glib::Texture* hovered_texture,
                            glib::Texture* pressed_texture):
                 AbstractButton(location, idle_texture, hovered_texture,
                                pressed_texture) {}


gui::RectButton::
//==============================================================================


// CircleButton
//==============================================================================
gui::CircleButton::CircleButton(const glib::FloatRect& location,
                                const glib::Circle& circle,
                                glib::Texture* idle_texture,
                                glib::Texture* hovered_texture,
                                glib::Texture* pressed_texture):
                   AbstractButton(location, idle_texture, hovered_texture,
                                  pressed_texture), m_circle(circle) {}
//==============================================================================
