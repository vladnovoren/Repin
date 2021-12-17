#include "app.hpp"


App::App():
     m_render_window(glib::Vector2f(gui::APP_WIDTH, gui::APP_HEIGHT), "Repin") {
}

App::~App() = default;


App& App::GetInstance() {
  static App instance;
  return instance;
}


void App::Exec() {
  while (m_widget_manager.IsOpen()) {
    // double prev_time = m_render_window.ResetTime();
    bool is_polled = true;
    while (is_polled) {
      m_widget_manager.GetAndProcessEvent(&m_render_window, is_polled);
    }
    m_widget_manager.DeleteMatched();
    m_widget_manager.Draw(&m_render_window);
    // double curr_time = m_render_window.ResetTime();
    // printf("FPS: %lf\n", 1.f / (curr_time - prev_time));
  }
}


glib::RenderWindow* App::GetRenderWindow() {
  return &m_render_window;
}


int main() {
  App& app = App::GetInstance();
  app.Exec();
  return 0;
}
