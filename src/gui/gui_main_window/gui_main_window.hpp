#ifndef GUI_MAIN_WINDOW_HPP
#define GUI_MAIN_WINDOW_HPP


#include "gui_abstract_container_widget.hpp"
#include "gui_window.hpp"
#include "gui_main_menu.hpp"
#include "gui_app_config.hpp"
#include "gui_tool_bar.hpp"


namespace gui {
  class MainWindow: public AbstractContainerWidget {
   protected:
    MainWindow();
    ~MainWindow() = default;

    MainMenu* m_main_menu = MainMenu::GetInstance();
   public:
    static MainWindow* GetInstance();

    glib::IntRect GetValidBoundsForContent() const override;

    void AddWindow(Window* window);
    void AddMainMenu(MainMenu* main_menu);
    void AddToolBar();
  };
}


#endif /* gui_main_window.hpp */
