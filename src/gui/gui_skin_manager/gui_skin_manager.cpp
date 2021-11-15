#include "gui_skin_manager.hpp"


gui::AbstractButtonSkin::~AbstractButtonSkin() = default;


gui::ButtonSkinKeeper::ButtonSkinKeeper(const char* folder_path) {
  assert(folder_path != nullptr);

  LoadFromFolder(folder_path);
}


void gui::ButtonSkinKeeper::LoadFromFolder(const char* folder_path) {
  assert(folder_path);

  char* idle_texture_path    = strdup(folder_path);
  char* hovered_texture_path = strdup(folder_path);
  char* pressed_texture_path = strdup(folder_path);

  idle_texture_path    = strcat(idle_texture_path, "/IdleTexture.png");
  hovered_texture_path = strcat(hovered_texture_path, "/HoveredTexture.png");
  pressed_texture_path = strcat(pressed_texture_path, "/PressedTexture.png");

  m_idle_texture.LoadFromFile(idle_texture_path);
  m_hovered_texture.LoadFromFile(hovered_texture_path);
  m_pressed_texture.LoadFromFile(pressed_texture_path);

  free(pressed_texture_path);
  free(hovered_texture_path);
  free(idle_texture_path);
}


void gui::ButtonSkinKeeper::LoadToSkin(AbstractButtonSkin* abstract_button_skin) {
  assert(abstract_button_skin != nullptr);

  abstract_button_skin->m_idle_texture    = &m_idle_texture;
  abstract_button_skin->m_hovered_texture = &m_hovered_texture;
  abstract_button_skin->m_pressed_texture = &m_pressed_texture;
}


gui::TitleBarSkinKeeper::TitleBarSkinKeeper(const char* folder_path) {
  assert(folder_path != nullptr);

  LoadFromFolder(folder_path);
}


void gui::TitleBarSkinKeeper::LoadFromFolder(const char* folder_path) {
  assert(folder_path != nullptr);

  char* left_texture_path   = strdup(folder_path);
  char* middle_texture_path = strdup(folder_path);
  char* right_texture_path  = strdup(folder_path);

  left_texture_path = strcat(left_texture_path, "/LeftTexture.png");
  middle_texture_path = strcat(middle_texture_path, "/MiddleTexture.png");
  right_texture_path = strcat(right_texture_path, "/RightTexture.png");

  m_left_texture.LoadFromFile(left_texture_path);
  m_middle_texture.LoadFromFile(middle_texture_path);
  m_right_texture.LoadFromFile(right_texture_path);

  free(right_texture_path);
  free(middle_texture_path);
  free(left_texture_path);
}


void gui::TitleBarSkinKeeper::LoadToSkin(TitleBarSkin* title_bar_skin) {
  assert(title_bar_skin);

  title_bar_skin->m_left_texture   = &m_left_texture;
  title_bar_skin->m_middle_texture = &m_middle_texture;
  title_bar_skin->m_right_texture  = &m_right_texture;
}
