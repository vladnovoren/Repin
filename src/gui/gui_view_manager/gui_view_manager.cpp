#include "gui_view_manager.hpp"


gui::ViewManager::ViewManager() {
  m_skin_manager.SetMinimizeButtonSkin(new CircleButtonSkin());
  m_skin_manager.SetMaximizeButtonSkin(new CircleButtonSkin());
  m_skin_manager.SetCloseButtonSkin(new CircleButtonSkin());
  m_skin_manager.SetTitleBarSkin(new TitleBarSkin());
  m_skin_manager.LoadFromFolder("Skins/aqua");
  TitleBar* title_bar = new TitleBar;
  title_bar->AddSkin(m_skin_manager.GetTitleBarSkin());
  title_bar->SetLocation(glib::IntRect(glib::Vector2i(0, 0), glib::Vector2i(800, 21)));
  m_root = title_bar;
}


gui::ViewManager::~ViewManager() {
  delete m_root;
}


void gui::ViewManager::Draw(glib::RenderWindow* render_window) {
  assert(render_window != nullptr);

  render_window->Clear();
  m_root->Draw(render_window, glib::Vector2i(0, 0));
  render_window->Display();
}


gui::ViewManager& gui::ViewManager::GetInstance() {
  static ViewManager instance;
  return instance;
}


void gui::ViewManager::AddMouseActiveView(AbstractView* view) {
  assert(view != nullptr);

  m_mouse_active_views.push_front(view);
}


void gui::ViewManager::RemoveMouseActiveView(AbstractView* view) {
  assert(view != nullptr);

  for (auto it =  m_mouse_active_views.begin();
            it != m_mouse_active_views.end();
            ++it) {
    auto view_ptr = *it;
    assert(view_ptr != nullptr);
    if (view_ptr == view) {
      m_mouse_active_views.erase(it);
      break;
    }
  }
}


gui::AbstractView* gui::ViewManager::GetRoot() const {
  return m_root;
}


gui::EventResult gui::ViewManager::ProcessEvent(AbstractView* view
                                                sf::Event sf_event) {
  assert(view          != nullptr);

  switch (sf_event.type) {
    case sf::Event::Closed:
      printf("closed\n");
      is_open = false;
      return view->OnClose();

    case sf::Event::MouseButtonPressed:
      printf("pressed\n");
      return view->OnMouseButtonPressed(mouse_position, button);

    case sf::Event::MouseButtonReleased:
      printf("released\n");
      return view->OnMouseButtonReleased(mouse_position, button);

    case sf::Event::MouseMoved:
      printf("move\n");
      return view->OnMouseMove(mouse_position);

    default:
      return view->OnUnknownEvent();
  }
}


gui::EventResult gui::ViewManager::GetAndProcessEvent(glib::RenderWindow* render_window,
                                                      AbstractView* view) {
  assert(render_window != nullptr);
  assert(view          != nullptr);

  sf::Event sf_event;
  if (!)

  switch (sf_event.type) {
    case sf::Event::Closed:
      printf("closed\n");
      is_open = false;
      return view->OnClose();

    case sf::Event::MouseButtonPressed:
      printf("pressed\n");
      return view->OnMouseButtonPressed(mouse_position, button);

    case sf::Event::MouseButtonReleased:
      printf("released\n");
      return view->OnMouseButtonReleased(mouse_position, button);

    case sf::Event::MouseMoved:
      printf("move\n");
      return view->OnMouseMove(mouse_position);

    default:
      return view->OnUnknownEvent();
  }
}


bool gui::ViewManager::IsOpen() const {
  return is_open;
}
