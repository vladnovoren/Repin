#include "gui_button_skin.hpp"


gui::AbstractButtonSkin::AbstractButtonSkin(const glib::Texture& texture,
                                            const glib::IntRect& idle_texture_location,
                                            const glib::IntRect& hovered_texture_location,
                                            const glib::IntRect& pressed_texture_location):
                         m_texture(texture),
                         m_curr_texture_location(idle_texture_location),
                         m_idle_texture_location(idle_texture_location),
                         m_hovered_texture_location(hovered_texture_location),
                         m_pressed_texture_location(pressed_texture_location) {}


gui::AbstractButtonSkin::~AbstractButtonSkin() = default;


void gui::AbstractButtonSkin::Render(const glib::Vector2i& size) {
  m_render_texture.Resize(size);
  m_render_texture.CopyTexture(m_source_texture, glib::Vector2f(), m_curr_texture_location);
  m_render_texture.Display();
  m_texture = m_render_texture.GetTexture();
}


void gui::AbstractButtonSkin::Copy(glib::RenderTarget* render_target,
                                   const glib::Vector2i& position) const {
  assert(render_target != nullptr);

  render_target->CopyTexture(m_texture, position);
}


bool gui::AbstractButtonSkin::LoadFromFolder(const char* folder_path) {
  assert(folder_path != nullptr);

  char* texture_path = (char*)calloc(strlen(folder_path) + strlen("/texture.png") + 1, sizeof(char));
  strcpy(texture_path, folder_path);
  strcat(texture_path, "/texture.png");

  char* map_path = (char*)calloc(strlen(folder_path) + strlen("/map.txt") + 1, sizeof(char));
  strcpy(map_path, folder_path);
  strcat(map_path, "/map.txt");

  if (!m_texture.LoadFromFile(texture_path)) {
    return false;
  }

  FILE* map = fopen(map_path, "rb");
  if (map == nullptr) {
    printf("no map in path [%s]\n", map_path);
    return false;
  }

  if (fscanf(map, "%d %d %d %d", &m_idle_texture_location.m_position.x, &m_idle_texture_location.m_position.y, &m_idle_texture_location.m_size.x, &m_idle_texture_location.m_size.y) != 4) {
    printf("invalid map.txt\n");
    return false;
  }
  if (fscanf(map, "%d %d %d %d", &m_hovered_texture_location.m_position.x, &m_hovered_texture_location.m_position.y, &m_hovered_texture_location.m_size.x, &m_idle_texture_location.m_size.y) != 4) {
    printf("invalid map.txt\n");
    return false;
  }
  if (fscanf(map, "%d %d %d %d", &m_pressed_texture_location.m_position.x, &m_pressed_texture_location.m_position.y, &m_pressed_texture_location.m_size.x, &m_idle_texture_location.m_size.y) != 4) {
    printf("invadid map.txt\n");
    return false;
  }

  fclose(map);
  free(map_path);
  free(texture_path);

  return true;
}


gui::RectButtonSkin::RectButtonSkin(const glib::Texture& texture,
                                    const glib::IntRect& idle_texture_location,
                                    const glib::IntRect& hovered_texture_location,
                                    const glib::IntRect& pressed_texture_location):
                     AbstractButtonSkin(texture, idle_texture_location,
                                        hovered_texture_location,
                                        pressed_texture_location) {}


bool gui::RectButtonSkin::IsPointInside(const glib::IntRect& location,
                                        const glib::Vector2i& point) const {
  return location.IsPointInRect(point);
}


gui::CircleButtonSkin::CircleButtonSkin(const glib::Texture& texture,
                                        const glib::IntRect& idle_texture_location,
                                        const glib::IntRect& hovered_texture_location,
                                        const glib::IntRect& pressed_texture_location):
                       AbstractButtonSkin(texture, idle_texture_location,
                                          hovered_texture_location,
                                          pressed_texture_location) {}


bool gui::CircleButtonSkin::IsPointInside(const glib::IntRect& location,
                                          const glib::Vector2i& point) const {
  glib::IntCircle circle(location.m_position + 0.5 * location.m_size, 0.5 * location.m_size.x);
  return circle.IsPointInside(point);
}
