#include "gui_main_menu.hpp"


gui::MainMenu::MainMenu(const glib::IntRect& location):
               AbstractContainerWidget(location) {}


gui::EventResult gui::MainMenu::OnMouseButtonPressed(glib::Vector2i local_mouse_position,
                                                     glib::Vector2i global_mouse_position,
                                                     MouseButton button) {
  for (auto child_it =  m_children.begin();
            child_it != m_children.end();
            ++child_it) {
    auto child_ptr = *child_it;
    
  }
}


gui::EventResult gui::MainMenu::OnMouseButtonReleased(glib::Vector2i local_mouse_position,
                                                      glib::Vector2i global_mouse_position,
                                                      MouseButton button) {
  
}
