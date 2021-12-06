#ifndef GUI_MAIN_MENU_HPP
#define GUI_MAIN_MENU_HPP


#include "glib.hpp"
#include "gui_abstract_container_widget.hpp"


namespace gui {
  class MainMenu {
   protected:
   public:
    MainMenu() = default;
    MainMenu(const glib::IntRect& location);
    ~MainMenu() = default;

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


#endif /* gui_main_menu.hpp */
