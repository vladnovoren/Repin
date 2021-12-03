#include "gui_view_manager.hpp"


gui::ViewManager::ViewManager() {
  m_skin_manager.SetMinimizeButtonSkin(new CircleButtonSkin());
  m_skin_manager.SetMaximizeButtonSkin(new CircleButtonSkin());
  m_skin_manager.SetCloseButtonSkin   (new CircleButtonSkin());
  m_skin_manager.SetTitleBarSkin      (new TitleBarSkin());
  m_skin_manager.LoadFromFolder("Skins/aqua");

  TitleBar* title_bar = new TitleBar;
  title_bar->SetSkin(m_skin_manager.GetTitleBarSkin());
  title_bar->SetLocation(glib::IntRect(glib::Vector2i(0, 0), glib::Vector2i(1200, 21)));

  CloseViewFunctor* close_view_functor = new CloseViewFunctor(title_bar);

  Button* close_button = new Button(close_view_functor,
                                    m_skin_manager.GetCloseButtonSkin());
  close_button->SetLocation(glib::IntRect(glib::Vector2i(1181, 3), glib::Vector2i(14, 15)));

  title_bar->AddCloseButton(close_button);

  m_root = title_bar;
}


gui::ViewManager::~ViewManager() {
  delete m_root;
}


void gui::ViewManager::Draw(glib::RenderWindow* render_window) {
  assert(render_window != nullptr);

  render_window->Clear();
  if (m_root != nullptr) {
    m_root->Draw(render_window, glib::Vector2i(0, 0));
  }
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


void gui::ViewManager::DeleteMatched() {
  if (m_root == nullptr) {
    return;
  }
  if (m_mouse_active_view != nullptr) {
    if (m_mouse_active_view->ShouldClose()) {
      m_mouse_active_view = nullptr;
    }
  }
  m_root->DeleteMatched();
  if (m_root->ShouldClose()) {
    delete m_root;
    m_root = nullptr;
  }
}


void gui::ViewManager::RemoveMouseActiveView(AbstractView* view) {
  assert(view != nullptr);
  
  if (view == m_mouse_active_view) {
    m_mouse_active_view = nullptr;
  } else {
    printf("tried to unfocus view that isn't under mouse\n");
  }
}


gui::AbstractView* gui::ViewManager::GetRoot() {
  return m_root;
}


gui::AbstractView* gui::ViewManager::GetMouseActiveView() {
  return m_mouse_active_view;
}


gui::EventResult gui::ViewManager::ProcessEvent(AbstractView* view,
                                                const sf::Event& sf_event,
                                                bool force) {
  assert(view != nullptr);

  MouseButton button = SFMLToGUIMouseButton(sf_event.mouseButton.button);
  glib::Vector2i mouse_position = GetMousePositionFromSfEvent(sf_event);

  switch (sf_event.type) {
    case sf::Event::Closed:
      m_is_open = false;
      return view->OnClose();

    case sf::Event::MouseButtonPressed:
      if (view->IsPointInside(mouse_position) || force) {
        return view->OnMouseButtonPressed(mouse_position, button);
      } else {
        return EventResult::NOT_PROCESSED;
      }

    case sf::Event::MouseButtonReleased:
      if (view->IsPointInside(mouse_position) || force) {
        return view->OnMouseButtonReleased(mouse_position, button);
      } else {
        return EventResult::NOT_PROCESSED;
      }

    case sf::Event::MouseMoved:
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


gui::EventResult gui::ViewManager::GetAndProcessEvent(glib::RenderWindow* render_window,
                                                      bool& is_pooled) {
  assert(render_window != nullptr);

  sf::Event sf_event;
  is_pooled = render_window->PollEvent(&sf_event);
  if (!is_pooled) {
    return EventResult::NO_EVENT;
  }

  if (IsCloseEvent(sf_event)) {
    m_is_open = false;
    return EventResult::PROCESSED;
  }

  if (m_root == nullptr) {
    return EventResult::NOT_PROCESSED;
  }


  if (IsMouseEvent(sf_event)) {
    ProcessMouseEventOnSignedView(render_window, sf_event);
  }

  return ProcessEvent(m_root, sf_event);
}


bool gui::ViewManager::IsOpen() const {
  return m_is_open;
}
