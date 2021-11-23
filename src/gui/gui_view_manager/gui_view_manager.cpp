#include "gui_view_manager.hpp"


gui::ViewManager::ViewManager(): m_skin_manager("Skins/aqua") {
  CircleButtonSkin* close_button_skin = new CircleButtonSkin;
  TitleBarSkin*     title_bar_skin    = new TitleBarSkin;
  DefaultViewSkin*  window_skin       = new DefaultViewSkin;
  m_skin_manager.GetCloseButtonSkinKeeper().LoadToSkin(close_button_skin);
  m_skin_manager.GetTitleBarSkinKeeper().LoadToSkin(title_bar_skin);
  window_skin->m_location = glib::IntRect(glib::Vector2i(0, 0), glib::Vector2i(300, 300));
  title_bar_skin->m_location = glib::IntRect(glib::Vector2i(0, 0), glib::Vector2i(300, 21));
  close_button_skin->m_location = glib::IntRect(glib::Vector2i(281, 2), glib::Vector2i(14, 15));
  close_button_skin->m_circle = glib::IntCircle(glib::Vector2i(7, 7), 7);

  Window* window = new Window(window_skin);
  CloseViewFunctor* close_window_functor = new CloseViewFunctor(window);
  Button* close_button = new Button(close_window_functor, close_button_skin);
  TitleBar* title_bar = new TitleBar(title_bar_skin, nullptr, nullptr,
                                     close_button, nullptr, MoveFunctor(window));
  window->AddTitleBar(title_bar);
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

  render_window->Clear();
  m_root->Draw(render_window, glib::Vector2i(0, 0));
  render_window->Display();
}
