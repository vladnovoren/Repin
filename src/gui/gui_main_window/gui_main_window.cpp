#include "gui_main_window.hpp"


gui::MainWindow::MainWindow() {
  SetLocation(glib::IntRect(glib::Vector2i(),
                            glib::Vector2i(APP_WIDTH, APP_HEIGHT)));
}


gui::MainWindow* gui::MainWindow::GetInstance() {
  static MainWindow* instance = new MainWindow;
  return instance;
}


gui::EventResult gui::MainWindow::OnMouseButtonPressed(glib::Vector2i local_mouse_position,
                                                       glib::Vector2i global_mouse_position,
                                                       MouseButton button) {

}
