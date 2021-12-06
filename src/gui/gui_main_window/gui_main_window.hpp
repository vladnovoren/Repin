#ifndef GUI_MAIN_WINDOW_HPP
#define GUI_MAIN_WINDOW_HPP


#include "gui_abstract_container_widget.hpp"
#include ""


namespace gui {
  class MainWindow: public AbstractContainerWidget {
   private:
    MainWindow();
    ~MainWindow() = default;
   public:
    static MainWindow* GetInstance() const;
  };
}


#endif /* gui_main_window.hpp */
