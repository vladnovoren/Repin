#ifndef APP_HPP
#define APP_HPP


#include "gui.hpp"


class App {
 private:
  App();
  ~App();

  glib::RenderWindow m_render_window;
  gui::ViewManager& m_view_manager = gui::ViewManager::GetInstance();
 public:
  static App& GetInstance();

  void Exec();
};


#endif /* app.hpp */
