#include "gui_skin_manager.hpp"


gui::SkinManager::SkinManager() {
  LoadSanFranciscoFont();
}


gui::SkinManager::SkinManager(AbstractButtonSkin* minimize_button_skin,
                              AbstractButtonSkin* maximize_button_skin,
                              AbstractButtonSkin* close_button_skin,
                              TitleBarSkin* title_bar_skin,
                              WindowSkin* window_skin):
                  m_minimize_button_skin(minimize_button_skin),
                  m_maximize_button_skin(maximize_button_skin),
                  m_close_button_skin(close_button_skin),
                  m_title_bar_skin(title_bar_skin),
                  m_window_skin(window_skin) {
  assert(minimize_button_skin != nullptr);
  assert(maximize_button_skin != nullptr);
  assert(close_button_skin    != nullptr);
  assert(title_bar_skin       != nullptr);
  assert(window_skin          != nullptr);

  LoadSanFranciscoFont();
}


gui::SkinManager::~SkinManager() {
  delete m_san_francisco_font;
}


void gui::SkinManager::LoadSanFranciscoFont() {
  m_san_francisco_font = new glib::Font("SanFrancisco/SF-Pro-Display-Regular.otf");
  assert(m_san_francisco_font != nullptr);
}


bool gui::SkinManager::LoadFromFolder(const char* folder_path) {
  assert(folder_path != nullptr);

  char* minimize_button_path = (char*)calloc(strlen(folder_path) + strlen("/MinimizeButton") + 1, sizeof(char));
  char* maximize_button_path = (char*)calloc(strlen(folder_path) + strlen("/MaximizeButton") + 1, sizeof(char));
  char* close_button_path    = (char*)calloc(strlen(folder_path) + strlen("/CloseButton") + 1,    sizeof(char));
  char* title_bar_path       = (char*)calloc(strlen(folder_path) + strlen("/TitleBar") + 1,       sizeof(char));
  char* window_path          = (char*)calloc(strlen(folder_path) + strlen("/Window") + 1,         sizeof(char));

  strcpy(minimize_button_path, folder_path);
  strcpy(maximize_button_path, folder_path);
  strcpy(close_button_path,    folder_path);
  strcpy(title_bar_path,       folder_path);
  strcpy(window_path,          folder_path);

  minimize_button_path = strcat(minimize_button_path, "/MinimizeButton");
  maximize_button_path = strcat(maximize_button_path, "/MaximizeButton");
  close_button_path    = strcat(close_button_path,    "/CloseButton");
  title_bar_path       = strcat(title_bar_path,       "/TitleBar");
  window_path          = strcat(window_path,          "/Window");

  if (!m_minimize_button_skin->LoadFromFolder(minimize_button_path)) {
    return false;
  }
  if (!m_maximize_button_skin->LoadFromFolder(maximize_button_path)) {
    return false;
  }
  if (!m_close_button_skin->LoadFromFolder(close_button_path)) {
    return false;
  }
  if (!m_title_bar_skin->LoadFromFolder(title_bar_path)) {
    return false;
  }
  if (!m_window_skin->LoadFromFolder(window_path)) {
    return false;
  }

  free(minimize_button_path);
  free(maximize_button_path);
  free(close_button_path);
  free(title_bar_path);
  free(window_path);

  return true;
}


void gui::SkinManager::SetMinimizeButtonSkin(AbstractButtonSkin* minimize_button_skin) {
  assert(minimize_button_skin != nullptr);

  delete m_minimize_button_skin;
  m_minimize_button_skin = minimize_button_skin;
}


void gui::SkinManager::SetMaximizeButtonSkin(AbstractButtonSkin* maximize_button_skin) {
  assert(maximize_button_skin != nullptr);

  delete m_maximize_button_skin;
  m_maximize_button_skin = maximize_button_skin;
}


void gui::SkinManager::SetCloseButtonSkin(AbstractButtonSkin* close_button_skin) {
  assert(close_button_skin != nullptr);

  delete m_close_button_skin;
  m_close_button_skin = close_button_skin;
}


void gui::SkinManager::SetTitleBarSkin(TitleBarSkin* title_bar_skin) {
  assert(title_bar_skin != nullptr);

  delete m_title_bar_skin;
  m_title_bar_skin = title_bar_skin;
}


void gui::SkinManager::SetWindowSkin(WindowSkin* window_skin) {
  assert(window_skin != nullptr);

  delete m_window_skin;
  m_window_skin = window_skin;
}


gui::AbstractButtonSkin* gui::SkinManager::GetMinimizeButtonSkin() const {
  return m_minimize_button_skin;
}


gui::AbstractButtonSkin* gui::SkinManager::GetMaximizeButtonSkin() const {
  return m_maximize_button_skin;
}


gui::AbstractButtonSkin* gui::SkinManager::GetCloseButtonSkin() const {
  return m_close_button_skin;
}


gui::TitleBarSkin* gui::SkinManager::GetTitleBarSkin() const {
  return m_title_bar_skin;
}


gui::WindowSkin* gui::SkinManager::GetWindowSkin() const {
  return m_window_skin;
}


glib::Font* gui::SkinManager::GetSanFranciscoFont() const {
  return m_san_francisco_font;
}
