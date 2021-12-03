#include "gui_window.hpp"


gui::Window::Window(DefaultWidgetSkin* skin):
             AbstractWidget(skin) {
  assert(skin   != nullptr);
  assert(m_skin != nullptr);
}


void gui::Window::AddTitleBar(TitleBar* title_bar) {
  assert(title_bar != nullptr);

  m_title_bar = title_bar;
  m_children.push_front(title_bar);
}


void gui::Window
