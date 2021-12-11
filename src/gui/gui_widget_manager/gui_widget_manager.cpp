#include "gui_widget_manager.hpp"


gui::WidgetManager::WidgetManager() {
  MainMenu* main_menu = MainMenu::GetInstance();
  SkinManager& skin_manager = SkinManager::GetInstance();
  main_menu->SetSkin(skin_manager.GetMainMenuSkin());

  MainWindow* main_window = MainWindow::GetInstance();

  glib::Text title_text1("Serega Chernomyrdin", skin_manager.GetSanFranciscoFont());
  title_text1.SetFontSize(14);
  title_text1.SetColor(glib::ColorRGBA(0, 0, 0, 1));

  Canvas* canvas1 = new Canvas(glib::IntRect(glib::Vector2i(0, 21), glib::Vector2i(400, 279)));

  Window* window1 = new Window;
  window1->SetLocation(glib::IntRect(glib::Vector2i(0, 22), glib::Vector2i(400, 300)));
  MoveFunctor* window1_move_functor = new MoveFunctor(window1);

  Title* title1 = new Title;
  title1->SetLocation(glib::IntRect(glib::Vector2i(200, 0), glib::Vector2i()));
  title1->SetText(title_text1);

  TitleBar* title_bar1 = new TitleBar;
  title_bar1->SetMoveFunctor(window1_move_functor);
  title_bar1->SetSkin(skin_manager.GetTitleBarSkin());
  title_bar1->SetLocation(glib::IntRect(glib::Vector2i(0, 0), glib::Vector2i(400, 21)));

  CloseWidgetFunctor* close_widget_functor1 = new CloseWidgetFunctor(window1);

  Button* close_button1 = new Button(glib::IntRect(glib::Vector2i(381, 3), glib::Vector2i(14, 15)),
                                    close_widget_functor1,
                                    skin_manager.GetCloseButtonSkin());


  title_bar1->AddCloseButton(close_button1);
  title_bar1->AddTitle(title1);
  window1->AddTitleBar(title_bar1);
  window1->AddContent(canvas1);



  glib::Text title_text2("Miha Rogozin", skin_manager.GetSanFranciscoFont());
  title_text2.SetFontSize(14);
  title_text2.SetColor(glib::ColorRGBA(0, 0, 0, 1));

  Canvas* canvas2 = new Canvas(glib::IntRect(glib::Vector2i(0, 21), glib::Vector2i(800, 579)));

  Window* window2 = new Window;
  window2->SetLocation(glib::IntRect(glib::Vector2i(0, 22), glib::Vector2i(800, 600)));
  MoveFunctor* window2_move_functor = new MoveFunctor(window2);

  Title* title2 = new Title;
  title2->SetLocation(glib::IntRect(glib::Vector2i(400, 0), glib::Vector2i()));
  title2->SetText(title_text2);

  TitleBar* title_bar2 = new TitleBar;
  title_bar2->SetMoveFunctor(window2_move_functor);
  title_bar2->SetSkin(skin_manager.GetTitleBarSkin());
  title_bar2->SetLocation(glib::IntRect(glib::Vector2i(0, 0), glib::Vector2i(800, 21)));

  CloseWidgetFunctor* close_widget_functor2 = new CloseWidgetFunctor(window2);

  Button* close_button2 = new Button(glib::IntRect(glib::Vector2i(781, 3), glib::Vector2i(14, 15)),
                                    close_widget_functor2,
                                    skin_manager.GetCloseButtonSkin());


  title_bar2->AddCloseButton(close_button2);
  title_bar2->AddTitle(title2);
  window2->AddTitleBar(title_bar2);
  window2->AddContent(canvas2);


  main_window->AddWindow(window1);
  main_window->AddWindow(window2);

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
