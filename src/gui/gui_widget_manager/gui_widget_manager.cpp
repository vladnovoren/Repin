#include "gui_widget_manager.hpp"


gui::WidgetManager::WidgetManager() {
  MainMenu* main_menu = MainMenu::GetInstance();
  SkinManager& skin_manager = SkinManager::GetInstance();
  main_menu->SetSkin(skin_manager.GetMainMenuSkin());

  glib::Text title_text("Serega Chernomyrdin", skin_manager.GetSanFranciscoFont());
  title_text.SetFontSize(14);
  title_text.SetColor(glib::ColorRGBA(0, 0, 0, 1));

  Canvas* canvas = new Canvas(glib::IntRect(glib::Vector2i(0, 21), glib::Vector2i(800, 579)));

  Window* window = new Window;
  window->SetLocation(glib::IntRect(glib::Vector2i(0, 22), glib::Vector2i(800, 600)));
  MoveFunctor* window_move_functor = new MoveFunctor(window);

  Title* title = new Title;
  title->SetLocation(glib::IntRect(glib::Vector2i(400, 0), glib::Vector2i()));
  title->SetText(title_text);

  TitleBar* title_bar = new TitleBar;
  title_bar->SetMoveFunctor(window_move_functor);
  title_bar->SetSkin(skin_manager.GetTitleBarSkin());
  title_bar->SetLocation(glib::IntRect(glib::Vector2i(0, 0), glib::Vector2i(800, 21)));

  CloseWidgetFunctor* close_widget_functor = new CloseWidgetFunctor(window);

  Button* close_button = new Button(glib::IntRect(glib::Vector2i(781, 3), glib::Vector2i(14, 15)),
                                    close_widget_functor,
                                    skin_manager.GetCloseButtonSkin());

  MainWindow* main_window = MainWindow::GetInstance();

  title_bar->AddCloseButton(close_button);
  title_bar->AddTitle(title);
  window->AddTitleBar(title_bar);
  window->AddContent(canvas);
  main_window->AddWindow(window);
  main_window->AddMainMenu(main_menu);

  m_root = main_window;
}


gui::WidgetManager::~WidgetManager() {
  delete m_root;
}


void gui::WidgetManager::Draw(glib::RenderWindow* render_window) {
  assert(render_window != nullptr);

  render_window->Clear();
  if (m_root != nullptr) {
    m_root->Draw(render_window, glib::Vector2i(0, 0));
  }
  render_window->Display();
}


gui::WidgetManager& gui::WidgetManager::GetInstance() {
  static WidgetManager instance;
  return instance;
}


void gui::WidgetManager::AddMouseActiveWidget(AbstractWidget* widget) {
  assert(widget != nullptr);

  m_mouse_active_widget = widget;
}


void gui::WidgetManager::DeleteMatched() {
  if (m_root == nullptr) {
    return;
  }
  if (m_mouse_active_widget != nullptr) {
    if (m_mouse_active_widget->ShouldClose()) {
      m_mouse_active_widget = nullptr;
    }
  }
  m_root->DeleteMatched();
  if (m_root->ShouldClose()) {
    delete m_root;
    m_root = nullptr;
  }
}


void gui::WidgetManager::RemoveMouseActiveWidget(AbstractWidget* widget) {
  assert(widget != nullptr);
  
  if (widget == m_mouse_active_widget) {
    m_mouse_active_widget = nullptr;
  } else {
    printf("tried to unfocus widget that isn't under mouse\n");
  }
}


gui::AbstractWidget* gui::WidgetManager::GetRoot() {
  return m_root;
}


gui::AbstractWidget* gui::WidgetManager::GetMouseActiveWidget() {
  return m_mouse_active_widget;
}


gui::EventResult gui::WidgetManager::ProcessEvent(AbstractWidget* widget,
                                                const sf::Event& sf_event,
                                                bool force) {
  assert(widget != nullptr);

  MouseButton button = SFMLToGUIMouseButton(sf_event.mouseButton.button);
  glib::Vector2i mouse_position = GetMousePositionFromSfEvent(sf_event);
  glib::Vector2i local_mouse_position = widget->PointRelativeToParent(mouse_position);

  switch (sf_event.type) {
    case sf::Event::Closed:
      m_is_open = false;
      return widget->OnClose();

    case sf::Event::MouseButtonPressed:
      if (widget->IsPointInside(local_mouse_position) || force) {
        return widget->OnMouseButtonPressed(local_mouse_position, mouse_position, button);
      } else {
        return EventResult::NOT_PROCESSED;
      }

    case sf::Event::MouseButtonReleased:
      if (widget->IsPointInside(local_mouse_position) || force) {
        return widget->OnMouseButtonReleased(local_mouse_position, mouse_position, button);
      } else {
        return EventResult::NOT_PROCESSED;
      }

    case sf::Event::MouseMoved:
      if (widget->IsPointInside(local_mouse_position) || force) {
        return widget->OnMouseMove(local_mouse_position, mouse_position);
      } else {
        return EventResult::NOT_PROCESSED;
      }

    default:
      return widget->OnUnknownEvent();
  }
}


gui::EventResult gui::WidgetManager::ProcessMouseEventOnSignedWidget(glib::RenderWindow* render_window,
                                                                 const sf::Event& sf_event) {
  assert(render_window != nullptr);

  if (m_mouse_active_widget != nullptr) {
    return ProcessEvent(m_mouse_active_widget, sf_event, true);
  } else {
    return EventResult::NOT_PROCESSED;
  }
}


gui::EventResult gui::WidgetManager::GetAndProcessEvent(glib::RenderWindow* render_window,
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
    if (ProcessMouseEventOnSignedWidget(render_window, sf_event) == EventResult::PROCESSED) {
      return EventResult::PROCESSED;
    }
  }

  return ProcessEvent(m_root, sf_event);
}


bool gui::WidgetManager::IsOpen() const {
  return m_is_open;
}
