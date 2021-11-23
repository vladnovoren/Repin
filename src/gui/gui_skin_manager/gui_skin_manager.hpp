#ifndef GUI_SKIN_MANAGER_HPP
#define GUI_SKIN_MANAGER_HPP


#include "gui_button_skin.hpp"
#include "gui_title_bar_skin.hpp"
#include <cstring>


namespace gui {
  class AbstractSkinKeeper {
   public:
    AbstractSkinKeeper() = default;
    virtual ~AbstractSkinKeeper() = 0;

    virtual void LoadFromFolder(const char* folder_path) = 0;
  };


  class ButtonSkinKeeper: public AbstractSkinKeeper {
   protected:
    glib::Texture m_idle_texture;
    glib::Texture m_hovered_texture;
    glib::Texture m_pressed_texture;
   public:
    ButtonSkinKeeper() = default;
    ButtonSkinKeeper(const char* folder_path);
    ~ButtonSkinKeeper() override = default;

    void LoadFromFolder(const char* folder_path) override;
    void LoadToSkin(AbstractButtonSkin* abstract_button_skin);
  };


  class TitleBarSkinKeeper: public AbstractSkinKeeper {
   protected:
    glib::Texture m_left_texture;
    glib::Texture m_middle_texture;
    glib::Texture m_right_texture;
   public:
    TitleBarSkinKeeper() = default;
    TitleBarSkinKeeper(const char* folder_path);
    ~TitleBarSkinKeeper() override = default;

    void LoadFromFolder(const char* folder_path) override;
    void LoadToSkin(TitleBarSkin* title_bar_skin);
  };


  class SkinManager {
   protected:
    ButtonSkinKeeper   m_minimize_button;
    ButtonSkinKeeper   m_maximize_button;
    ButtonSkinKeeper   m_close_button;
    TitleBarSkinKeeper m_title_bar;
   public:
    SkinManager() = default;
    SkinManager(const char* folder_path);
    ~SkinManager() = default;

    ButtonSkinKeeper   GetMinimizeButtonSkinKeeper() const;
    ButtonSkinKeeper   GetMaximizeButtonSkinKeeper() const;
    ButtonSkinKeeper   GetCloseButtonSkinKeeper() const;
    TitleBarSkinKeeper GetTitleBarSkinKeeper() const;

    void LoadFromFolder(const char* folder_path);
  };
}


#endif /* gui_skin_manager.hpp */
