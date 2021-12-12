#include "gui_main_window.hpp"


gui::MainWindow::MainWindow() {
  SetLocation(glib::IntRect(0, 0, APP_WIDTH, APP_HEIGHT));
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


void gui::MainWindow::AddWindow(Window* window) {
  assert(window != nullptr);

  AddChild(window);
}


void gui::MainWindow::AddMainMenu(MainMenu* main_menu) {
  assert(main_menu != nullptr);

  AddChild(main_menu);
}


void gui::MainWindow::AddToolBar() {
  ToolBar* tool_bar = ToolBar::GetInstance();
  assert(tool_bar != nullptr);

  AddChild(tool_bar);
}