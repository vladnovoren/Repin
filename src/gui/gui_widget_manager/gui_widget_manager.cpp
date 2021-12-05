#include "gui_widget_manager.hpp"
#include "app.hpp"


gui::WidgetManager::WidgetManager() {
  m_skin_manager.SetMinimizeButtonSkin(new CircleButtonSkin());
  m_skin_manager.SetMaximizeButtonSkin(new CircleButtonSkin());
  m_skin_manager.SetCloseButtonSkin   (new CircleButtonSkin());
  m_skin_manager.SetTitleBarSkin      (new TitleBarSkin());
  m_skin_manager.LoadFromFolder       ("Skins/aqua");

  glib::Text title_text("Canvas", m_skin_manager.GetSanFranciscoFont());
  title_text.SetFontSize(14);
  title_text.SetColor(glib::ColorRGBA(0, 0, 0, 1));

  Title* title = new Title;
  title->SetLocation(glib::IntRect(glib::Vector2i(600, 0), glib::Vector2i()));
  title->SetText(title_text);

  sf::RenderWindow sf_render_window(sf::VideoMode(1200, 800), "Test window");

  TitleBar* title_bar = new TitleBar;
  title_bar->SetSkin(m_skin_manager.GetTitleBarSkin());
  title_bar->SetLocation(glib::IntRect(glib::Vector2i(0, 0), glib::Vector2i(1200, 21)));

  CloseWidgetFunctor* close_widget_functor    = new CloseWidgetFunctor(title_bar);
  CloseWidgetFunctor* maximize_widget_functor = new CloseWidgetFunctor(title_bar);
  CloseWidgetFunctor* minimize_widget_functor = new CloseWidgetFunctor(title_bar);

  Button* close_button = new Button(glib::IntRect(glib::Vector2i(1181, 3), glib::Vector2i(14, 15)),
                                    close_widget_functor,
                                    m_skin_manager.GetCloseButtonSkin());

  Button* maximize_button = new Button(glib::IntRect(glib::Vector2i(1162, 3), glib::Vector2i(14, 15)),
                                       maximize_widget_functor,
                                       m_skin_manager.GetMaximizeButtonSkin());

  Button* minimize_button = new Button(glib::IntRect(glib::Vector2i(1143, 3), glib::Vector2i(14, 15)),
                                       minimize_widget_functor,
                                       m_skin_manager.GetMinimizeButtonSkin());

  title_bar->AddCloseButton(close_button);
  title_bar->AddMaximizeButton(maximize_button);
  title_bar->AddMinimizeButton(minimize_button);
  title_bar->AddTitle(title);

  m_root = title_bar;
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
  mouse_position = widget->PointRelativeToParent(mouse_position);

  switch (sf_event.type) {
    case sf::Event::Closed:
      m_is_open = false;
      return widget->OnClose();

    case sf::Event::MouseButtonPressed:
      if (widget->IsPointInside(mouse_position) || force) {
        return widget->OnMouseButtonPressed(mouse_position, button);
      } else {
        return EventResult::NOT_PROCESSED;
      }

    case sf::Event::MouseButtonReleased:
      if (widget->IsPointInside(mouse_position) || force) {
        return widget->OnMouseButtonReleased(mouse_position, button);
      } else {
        return EventResult::NOT_PROCESSED;
      }

    case sf::Event::MouseMoved:
      if (widget->IsPointInside(mouse_position) || force) {
        return widget->OnMouseMove(mouse_position);
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
    ProcessMouseEventOnSignedWidget(render_window, sf_event);
  }

  return ProcessEvent(m_root, sf_event);
}


bool gui::WidgetManager::IsOpen() const {
  return m_is_open;
}
