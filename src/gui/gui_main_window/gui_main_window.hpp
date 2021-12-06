#ifndef GUI_MAIN_WINDOW_HPP
#define GUI_MAIN_WINDOW_HPP


#include "gui_abstract_container_widget.hpp"
#include "gui_app_config.hpp"

namespace gui {
  class MainWindow: public AbstractContainerWidget {
   private:
    MainWindow();
    ~MainWindow() = default;
   public:
    static MainWindow* GetInstance();

    EventResult OnMouseButtonPressed(glib::Vector2i local_mouse_position,
                                     glib::Vector2i global_mouse_position,
                                     MouseButton button);
    EventResult OnMouseButtonReleased(glib::Vector2i local_mouse_position,
                                      glib::Vector2i global_mouse_position,
                                      MouseButton button);
    EventResult OnMouseMove(glib::Vector2i new_local_mouse_position,
                            glib::Vector2i new_global_mouse_position);
  };
}


#endif /* gui_main_window.hpp */
