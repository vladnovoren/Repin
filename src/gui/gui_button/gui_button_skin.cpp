#include "gui_button_skin.hpp"


gui::AbstractButtonSkin::AbstractButtonSkin(const glib::IntRect& location,
                                            const glib::Texture* idle_texture,
                                            const glib::Texture* hovered_texture,
                                            const glib::Texture* pressed_texture):
                         DefaultViewSkin(location),
                         m_curr_texture(idle_texture),
                         m_idle_texture(idle_texture),
                         m_hovered_texture(hovered_texture),
                         m_pressed_texture(pressed_texture) {
  assert(idle_texture    != nullptr);
  assert(hovered_texture != nullptr);
  assert(pressed_texture != nullptr);
}


gui::AbstractButtonSkin::~AbstractButtonSkin() = default;


gui::RectButtonSkin::RectButtonSkin(const glib::IntRect& location,
                                    const glib::Texture* idle_texture,
                                    const glib::Texture* hovered_texture,
                                    const glib::Texture* pressed_texture):
                     AbstractButtonSkin(location, idle_texture,
                                        hovered_texture, pressed_texture) {}


void gui::RectButtonSkin::Draw(glib::RenderTarget* render_target,
                               const glib::Vector2i& position) {
  assert(render_target);

  glib::Vector2i new_position = position + m_location.m_position;
  render_target->CopyTexture(*m_curr_texture, new_position);
}


bool gui::RectButtonSkin::IsPointInside(glib::Vector2i point) {
  point -= m_location.m_position;
  return m_location.IsPointInRect(point);
}


gui::CircleButtonSkin::CircleButtonSkin(const glib::IntRect& location,
                                        const glib::Texture* idle_texture,
                                        const glib::Texture* hovered_texture,
                                        const glib::Texture* pressed_texture,
                                        const glib::IntCircle& circle):
                       AbstractButtonSkin(location, idle_texture,
                                          hovered_texture, pressed_texture),
                       m_circle(circle) {}


bool gui::CircleButtonSkin::IsPointInside(glib::Vector2i point) {
  point -= m_location.m_position;
  return m_circle.IsPointInside(point);
}


void gui::CircleButtonSkin::Draw(glib::RenderTarget* render_target,
                                 const glib::Vector2i& position) {
  assert(render_target != nullptr);

  glib::Vector2i new_position = position;
  new_position += m_location.m_position;

  render_target->CopyTexture(*m_curr_texture, new_position);
}
