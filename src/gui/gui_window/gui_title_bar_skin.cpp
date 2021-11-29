#include "gui_title_bar_skin.hpp"


gui::TitleBarSkin::TitleBarSkin(const glib::Texture& texture,
                                const glib::IntRect& left_location,
                                const glib::IntRect& middle_location,
                                const glib::IntRect& right_location):
                   m_texture(texture), m_left_location(left_location),
                   m_middle_location(middle_location),
                   m_right_location(right_location) {}


bool gui::TitleBarSkin::LoadFromFolder(const char* folder_path) {
  assert(folder_path != nullptr);

  size_t texture_path_len = strlen(folder_path) + strlen("/texture.png");
  char* texture_path = (char*)calloc(texture_path_len + 1, sizeof(char));
  strcpy(texture_path, folder_path);
  strcat(texture_path, "/texture.png");
  if (!m_texture.LoadFromFile(texture_path)) {
    free(texture_path);
    return false;
  }

  size_t map_path_len = strlen(folder_path) + strlen("/map.txt");
  char* map_path = (char*)calloc(map_path_len + 1, sizeof(char));
  strcpy(map_path, folder_path);
  strcat(map_path, "/map.txt");
  
  FILE* map = fopen(map_path, "rb");
  if (map == nullptr) {
    free(map_path);
    return false;
  }

  if (fscanf(map, "%d %d %d %d", &m_left_location.m_position.x,   &m_left_location.m_position.y,   &m_left_location.m_size.x,   &m_left_location.m_size.y) != 4) {
    printf("invalid map.txt\n");
    return false;
  }
  if (fscanf(map, "%d %d %d %d", &m_middle_location.m_position.x, &m_middle_location.m_position.y, &m_middle_location.m_size.x, &m_middle_location.m_size.y) != 4) {
    printf("invalid map.txt\n");
    return false;
  }
  if (fscanf(map, "%d %d %d %d", &m_right_location.m_position.x,  &m_right_location.m_position.y,  &m_right_location.m_size.x,  &m_right_location.m_size.y) != 4) {
    printf("invalid map.txt\n");
    return false;
  }

  fclose(map);
  free(map_path);
  free(texture_path);

  return true;
}


void gui::TitleBarSkin::Draw(glib::RenderTarget* render_target,
                             const glib::IntRect& location) {
  assert(render_target != nullptr);

  render_target->CopyTexture(m_texture, m_left_location.m_position, m_left_location);

  int n_middle = location.m_size.x - m_right_location.m_size.x - m_left_location.m_size.x;
  glib::Vector2i curr_position = location.m_position + glib::Vector2i(m_left_location.m_size.x, 0);
  for (int i = 0; i < n_middle; ++i) {
    render_target->CopyTexture(m_texture, curr_position, m_middle_location);
    curr_position += glib::Vector2i(1, 0);
  }

  render_target->CopyTexture(m_texture, curr_position, m_right_location);
}
