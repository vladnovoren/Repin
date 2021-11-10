#include "gui_button_skin.hpp"


gui::AbstractButtonSkin::AbstractButtonSkin(const glib::Vector2f& location,
                                            glib::Texture* idle_texture,
                                            glib::Texture* hovered_texture,
                                            glib::Texture* pressed_texture):
                         AbstractViewSkin(location),
                         m_curr_texture(idle_texture),
                         m_idle_texture(idle_texture),
                         m_hovered_texture(hovered_texture),
                         m_pressed_texture(pressed_texture) {
  assert(idle_texture != nullptr);
  assert(hovered_texture != nullptr);
  assert(pressed_texture != nullptr);
}


gui::RectButtonSkin::RectButtonSkin(const glib::Vector2f& location,
                                    glib::Texture* idle_texture,
                                    glib::Texture* hovered_texture,
                                    glib::Texture* pressed_texture,
                                    const glib::FloatRect& rect):
                     AbstractButtonSkin(location, idle_texture,
                                        hovered_texture, pressed_texture),
                     m_rect(rect) {}


void gui::RectButtonSkin::Draw(glib::RenderTarget* render_target) {
  assert(render_target);

  render_target->CopyTexture(*m_curr_texture, m_location);
}

                     
bool gui::RectButtonSkin::IsPointInside(const glib::Vector2f& point) {
  return m_rect.IsPointInRect(point);
}


gui::CircleButtonSkin::CircleButtonSkin(const glib::Vector2f& locaiton,
                                        glib::Texture* idle_texture,
                                        glib::Texture* hovered_texture,
                                        glib::Texture* pressed_texture,
                                        const glib::FloatRect& circle):
                       AbstractButtonSkin(location, idle_texture,
                                          hovered_texture, pressed_texture),
                       m_circle(circle) {}


bool gui::CircleButtonSkin::IsPointInside(const glib::Vector2f& point) {
  return m_circle.IsPointInside(point);
}


void gui::CircleButtonSkin::Draw(glib::RenderTarget* render_target,
                                 const glib::Vector2f& position) {
  assert(render_target != nullptr);

  glib::FloatRect absolute_location = m_location;
  absolute_location.m_position += position;

  render_target->CopyTexture(*m_curr_texture, m_location);
}
