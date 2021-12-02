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

  m_mouse_active_view = view;
}


void gui::ViewManager::RemoveMouseActiveView(AbstractView* view) {
  assert(view != nullptr);

  m_mouse_active_view = nullptr;
}


gui::AbstractView* gui::ViewManager::GetRoot() const {
  return m_root;
}


gui::EventResult gui::ViewManager::ProcessEvent(AbstractView* view,
                                                const sf::Event& sf_event,
                                                bool force) {
  assert(view != nullptr);

  MouseButton button = SFMLToGUIMouseButton(sf_event.mouseButton.button);
  glib::Vector2i mouse_position = GetMousePositionFromSfEvent(sf_event);

  switch (sf_event.type) {
    case sf::Event::Closed:
      // printf("closed\n");
      is_open = false;
      return view->OnClose();

    case sf::Event::MouseButtonPressed:
      // printf("pressed\n");
      if (view->IsPointInside(mouse_position) || force) {
        mouse_position = glib::Vector2i(sf_event.mouseButton.x, sf_event.mouseButton.y);
        return view->OnMouseButtonPressed(mouse_position, button);
      } else {
        return EventResult::NOT_PROCESSED;
      }

    case sf::Event::MouseButtonReleased:
      // printf("released\n");
      if (view->IsPointInside(mouse_position) || force) {
        // printf("pressed and entered\n");
        return view->OnMouseButtonReleased(mouse_position, button);
      } else {
        return EventResult::NOT_PROCESSED;
      }

    case sf::Event::MouseMoved:
      // printf("move\n");
      if (view->IsPointInside(mouse_position) || force) {
        return view->OnMouseMove(mouse_position);
      } else {
        return EventResult::NOT_PROCESSED;
      }

    default:
      return view->OnUnknownEvent();
  }
}


gui::EventResult gui::ViewManager::ProcessMouseEventOnSignedView(glib::RenderWindow* render_window,
                                                                 const sf::Event& sf_event) {
  assert(render_window != nullptr);

  if (m_mouse_active_view != nullptr) {
    return ProcessEvent(m_mouse_active_view, sf_event, true);
  } else {
    return EventResult::NOT_PROCESSED;
  }
}


gui::EventResult gui::ViewManager::GetAndProcessEvent(glib::RenderWindow* render_window, bool& is_pooled) {
  assert(render_window != nullptr);

  sf::Event sf_event;
  is_pooled = render_window->PollEvent(&sf_event);
  if (!is_pooled) {
    return EventResult::NO_EVENT;
  }

  if (IsMouseEvent(sf_event)) {
    ProcessMouseEventOnSignedView(render_window, sf_event);
  }

  return ProcessEvent(m_root, sf_event);
}


bool gui::ViewManager::IsOpen() const {
  return is_open;
}
