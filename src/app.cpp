#include "app.hpp"


App::App():
     m_render_window(glib::Vector2f(800, 600), "Repin") {}

App::App(const App&) {};
App::~App() = default;


App& App::GetInstance() {
  static App instance;
  return instance;
}


void App::Exec() {
  while (m_view_manager.IsOpen()) {
    m_view_manager.GetAndProcessEvent(&m_render_window);
    m_view_manager.Draw(&m_render_window);
  }
}


int main() {
  App& app = App::GetInstance();
  app.Exec();
  return 0;
}
