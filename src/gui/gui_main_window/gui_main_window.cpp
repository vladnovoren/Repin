#include "gui_main_window.hpp"


gui::MainWindow::MainWindow() {
  SetLocation(glib::IntRect(glib::Vector2i(),
                            glib::Vector2i(APP_WIDTH, APP_HEIGHT)));
}


gui::MainWindow* gui::MainWindow::GetInstance() {
  static MainWindow* instance = new MainWindow;
  return instance;
}


glib::IntRect gui::MainWindow::GetValidBoundsForContent() const {
  glib::IntRect bounds;
  bounds.m_position.y = m_main_menu->m_location.m_size.y;
  bounds.m_size = m_location.m_size;
  bounds.m_size.y -= m_main_menu->m_location.m_size.y;
  return bounds;
}
