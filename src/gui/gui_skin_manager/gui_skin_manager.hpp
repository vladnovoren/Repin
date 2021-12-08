#ifndef GUI_SKIN_MANAGER_HPP
#define GUI_SKIN_MANAGER_HPP


#include "gui_button_skin.hpp"
#include "gui_title_bar_skin.hpp"
#include "gui_main_menu_skin.hpp"
#include <cstring>


namespace gui {
  class SkinManager {
   protected:
    AbstractButtonSkin* m_minimize_button_skin = nullptr;
    AbstractButtonSkin* m_maximize_button_skin = nullptr;
    AbstractButtonSkin* m_close_button_skin    = nullptr;
    TitleBarSkin*       m_title_bar_skin       = nullptr;
    MainMenuSkin*       m_main_menu_skin       = nullptr;

    glib::Font*         m_san_francisco_font   = nullptr;
   public:
    SkinManager(const char* folder_path);
    ~SkinManager();

    void LoadSanFranciscoFont();

    char*               GetPath(const char* folder_path, const char* child_dir);

    bool                LoadLocationFromFile(FILE* file, glib::IntRect* location);
    AbstractButtonSkin* LoadButtonSkinFromFolder(const char* folder_path);
    TitleBarSkin*       LoadTitleBarSkinFromFolder(const char* folder_path);
    MainMenuSkin*       LoadMainMenuSkinFromFolder(const char* folder_path);


    AbstractButtonSkin* GetMinimizeButtonSkin() const;
    AbstractButtonSkin* GetMaximizeButtonSkin() const;
    AbstractButtonSkin* GetCloseButtonSkin() const;
    TitleBarSkin*       GetTitleBarSkin() const;
    MainMenuSkin*       GetMainMenuSkin() const;

    glib::Font*         GetSanFranciscoFont() const;

    bool LoadFromFolder(const char* folder_path);
  };
}


#endif /* gui_skin_manager.hpp */
