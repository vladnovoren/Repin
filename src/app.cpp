#include "app.hpp"


App::App():
m_render_window(glib::Vector2f(1200, 800), "Repin"),
m_view_manager() {}

App::App(const App&) {};
App::~App() = default;


App& App::GetInstance() {
  static App instance;
  return instance;
}


void App::Exec() {
  bool is_open = true;
  glib::Event* event = nullptr;
  while (is_open) {
    while ((event = m_render_window.PollEvent()) != nullptr) {
      if (event->Type() == glib::EventType::CLOSE_SYS_WINDOW) {
        is_open = false;
      } else {
        m_view_manager.Emit(event);
      }
      delete event;
    }
    m_view_manager.Draw(&m_render_window);
  }
}


int main() {
  App* invalid_app_ptr = nullptr;
  App& app = invalid_app_ptr->GetInstance();
  app.Exec();
  return 0;
}
