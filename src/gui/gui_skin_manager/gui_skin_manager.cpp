#include "gui_skin_manager.hpp"


gui::AbstractSkinKeeper::~AbstractSkinKeeper() = default;


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


gui::SkinManager::SkinManager(const char* folder_path) {
  LoadFromFolder(folder_path);
}


void gui::SkinManager::LoadFromFolder(const char* folder_path) {
  assert(folder_path != nullptr);

  char* minimize_button_path = strdup(folder_path);
  char* maximize_button_path = strdup(folder_path);
  char* close_button_path    = strdup(folder_path);
  char* title_bar_path       = strdup(folder_path);

  minimize_button_path = strcat(minimize_button_path, "/MinimizeButton");
  maximize_button_path = strcat(maximize_button_path, "/MaximizeButton");
  close_button_path    = strcat(close_button_path, "/CloseButton");
  title_bar_path       = strcat(title_bar_path, "/TitleBar");

  m_minimize_button.LoadFromFolder(minimize_button_path);
  m_maximize_button.LoadFromFolder(maximize_button_path);
  m_close_button.LoadFromFolder(close_button_path);
  m_title_bar.LoadFromFolder(title_bar_path);

  free(minimize_button_path);
  free(maximize_button_path);
  free(close_button_path);
  free(title_bar_path);
}


gui::ButtonSkinKeeper gui::SkinManager::GetMinimizeButtonSkinKeeper() const {
  return m_minimize_button;
}


gui::ButtonSkinKeeper gui::SkinManager::GetMaximizeButtonSkinKeeper() const {
  return m_maximize_button;
}


gui::ButtonSkinKeeper gui::SkinManager::GetCloseButtonSkinKeeper() const {
  return m_close_button;
}


gui::TitleBarSkinKeeper gui::SkinManager::GetTitleBarSkinKeeper() const {
  return m_title_bar;
}
