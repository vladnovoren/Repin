#ifndef GUI_SKIN_MANAGER_HPP
#define GUI_SKIN_MANAGER_HPP


#include "gui_button_skin.hpp"
#include "gui_title_bar_skin.hpp"
#include "gui_window_skin.hpp"
#include <cstring>


namespace gui {
  class SkinManager {
   protected:
    AbstractButtonSkin* m_minimize_button_skin = nullptr;
    AbstractButtonSkin* m_maximize_button_skin = nullptr;
    AbstractButtonSkin* m_close_button_skin    = nullptr;
    TitleBarSkin*       m_title_bar_skin       = nullptr;
    WindowSkin*         m_window_skin          = nullptr;

    glib::Font*         m_san_francisco_font   = nullptr;
   public:
    SkinManager();
    SkinManager(AbstractButtonSkin* minimize_button_skin,
                AbstractButtonSkin* maximize_button_skin,
                AbstractButtonSkin* close_button_skin,
                TitleBarSkin* title_bar_skin,
                WindowSkin* window_skin);
    ~SkinManager();

    void LoadSanFranciscoFont();

    void SetMinimizeButtonSkin(AbstractButtonSkin* minimize_button_skin);
    void SetMaximizeButtonSkin(AbstractButtonSkin* maximize_button_skin);
    void SetCloseButtonSkin(AbstractButtonSkin* close_button_skin);
    void SetTitleBarSkin(TitleBarSkin* title_bar_skin);
    void SetWindowSkin(WindowSkin* window_skin);

    AbstractButtonSkin* GetMinimizeButtonSkin() const;
    AbstractButtonSkin* GetMaximizeButtonSkin() const;
    AbstractButtonSkin* GetCloseButtonSkin() const;
    TitleBarSkin*       GetTitleBarSkin() const;
    WindowSkin*         GetWindowSkin() const;

    glib::Font*         GetSanFranciscoFont() const;

    bool LoadFromFolder(const char* folder_path);
  };
}


#endif /* gui_skin_manager.hpp */
