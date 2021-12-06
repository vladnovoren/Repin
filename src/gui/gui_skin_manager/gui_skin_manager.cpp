#include "gui_skin_manager.hpp"


gui::SkinManager::SkinManager(const char* folder_path) {
  assert(folder_path != nullptr);

  LoadFromFolder(folder_path);
  LoadSanFranciscoFont();
}


gui::SkinManager::~SkinManager() {
  delete m_san_francisco_font;
}


char* gui::SkinManager::GetPath(const char* folder_path, const char* child_dir) {
  assert(folder_path != nullptr);
  assert(child_dir   != nullptr);

  char* path = (char*)calloc(strlen(folder_path) + strlen(child_dir) + 1, sizeof(char));
  strcpy(path, folder_path);
  strcat(path, child_dir);
  return path;
}


void gui::SkinManager::LoadSanFranciscoFont() {
  m_san_francisco_font = new glib::Font("SanFrancisco/SF-Pro-Display-Bold.otf");
  assert(m_san_francisco_font != nullptr);
}


bool gui::SkinManager::LoadLocationFromFile(FILE* file, glib::IntRect* location) {
  assert(file     != nullptr);
  assert(location != nullptr);
  
  if (fscanf(file, "%d %d %d %d", &location->m_position.x,
                                  &location->m_position.y,
                                  &location->m_size.x,
                                  &location->m_size.y) != 4) {
    printf("invalid map.txt\n");
    return false;
  }
  return true;
}


bool gui::SkinManager::LoadFromFolder(const char* folder_path) {
  assert(folder_path != nullptr);

  delete m_minimize_button_skin;
  delete m_maximize_button_skin;
  delete m_close_button_skin;
  delete m_title_bar_skin;

  char* minimize_button_path = GetPath(folder_path, "/MinimizeButton");
  char* maximize_button_path = GetPath(folder_path, "/MaximizeButton");
  char* close_button_path    = GetPath(folder_path, "/CloseButton");
  char* title_bar_path       = GetPath(folder_path, "/TitleBar");

  bool result = true;

  if ((m_minimize_button_skin = LoadButtonSkinFromFolder(minimize_button_path)) == nullptr ||
      (m_maximize_button_skin = LoadButtonSkinFromFolder(maximize_button_path)) == nullptr ||
      (m_close_button_skin    = LoadButtonSkinFromFolder(close_button_path))    == nullptr ||
      (m_title_bar_skin       = LoadTitleBarSkinFromFolder(title_bar_path))     == nullptr) {
    result = false;
  }

  free(minimize_button_path);
  free(maximize_button_path);
  free(close_button_path);
  free(title_bar_path);

  return true;
}


gui::AbstractButtonSkin* gui::SkinManager::LoadButtonSkinFromFolder(const char* folder_path) {
  assert(folder_path != nullptr);

  char* texture_path = GetPath(folder_path, "/texture.png");
  char* map_path     = GetPath(folder_path, "/map.txt");

  FILE* map = fopen(map_path, "rb");
  if (map == nullptr) {
    printf("no map in path [%s]\n", map_path);
    return nullptr;
  }

  char* button_type = (char*)calloc(20, sizeof(char));
  fscanf(map, "%s", button_type);

  bool load_ok = true;

  AbstractButtonSkin* button_skin = nullptr;
  if (strcmp(button_type, "circle") == 0) {
    button_skin = new CircleButtonSkin;
  } else if (strcmp(button_type, "rectangle") == 0) {
    button_skin = new RectButtonSkin;
  } else {
    printf("invalid button type\n");
    load_ok = false;
  }

  if (load_ok) {
    if (!button_skin->m_source_texture.LoadFromFile(texture_path)) {
      load_ok = false;
    }
  }

  if (load_ok) {
    if (!LoadLocationFromFile(map, &button_skin->m_idle_texture_location) ||
        !LoadLocationFromFile(map, &button_skin->m_hovered_texture_location) ||
        !LoadLocationFromFile(map, &button_skin->m_pressed_texture_location)) {
      load_ok = false;
    }
  }

  if (!load_ok) {
    delete button_skin;
    button_skin = nullptr;
  }

  fclose(map);
  free(map_path);
  free(texture_path);
  free(button_type);

  return button_skin;
}


gui::TitleBarSkin* gui::SkinManager::LoadTitleBarSkinFromFolder(const char* folder_path) {
  assert(folder_path != nullptr);

  bool load_ok = true;

  TitleBarSkin* title_bar_skin = new TitleBarSkin;
  char* map_path = GetPath(folder_path, "/map.txt");
  FILE* map = fopen(map_path, "rb");
  if (map == nullptr) {
    load_ok = false;
  }

  char* texture_path = GetPath(folder_path, "/texture.png");
  if (load_ok) {
    if (!title_bar_skin->m_source_texture.LoadFromFile(texture_path)) {
      load_ok = false;
    }
  }

  if (load_ok) {
    if (!LoadLocationFromFile(map, &title_bar_skin->m_left_location) ||
        !LoadLocationFromFile(map, &title_bar_skin->m_middle_location) ||
        !LoadLocationFromFile(map, &title_bar_skin->m_right_location)) {
      load_ok = false;
    }
  }

  fclose(map);
  free(map_path);
  free(texture_path);

  if (!load_ok) {
    delete title_bar_skin;
    title_bar_skin = nullptr;
  }

  return title_bar_skin;
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


glib::Font* gui::SkinManager::GetSanFranciscoFont() const {
  return m_san_francisco_font;
}
