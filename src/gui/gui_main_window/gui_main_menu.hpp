#ifndef GUI_MAIN_MENU_HPP
#define GUI_MAIN_MENU_HPP


#include "glib.hpp"
#include "gui_abstract_container_widget.hpp"
#include "gui_main_menu_skin.hpp"


namespace gui {
  class MainMenu: public AbstractContainerWidget {
   protected:
    MainMenuSkin* m_skin = nullptr;
   public:
    MainMenu() = default;
    MainMenu(const glib::IntRect& location);
    ~MainMenu();

    void SetSkin(MainMenuSkin* skin);

    void Draw(glib::RenderTarget* render_target, const glib::Vector2i& position);
  };
}


#endif /* gui_main_menu.hpp */
