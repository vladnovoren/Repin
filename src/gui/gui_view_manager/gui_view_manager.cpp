#include "gui_view_manager.hpp"


gui::ViewManager::ViewManager() {
  
}


gui::ViewManager::~ViewManager() {
  delete m_root;
}


void gui::ViewManager::Emit(glib::Event* event) {
  assert(event != nullptr);

  m_event_emitter.Emit(event, m_root);
}


void gui::ViewManager::Draw(glib::RenderWindow* render_window) {
  assert(render_window != nullptr);

  m_root->Draw(render_window, glib::Vector2i(0, 0));
}
