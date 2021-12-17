#include "gui_widget_manager.hpp"


gui::WidgetManager::WidgetManager() {
  InitMainWindow();
  InitMainMenu();
  InitToolBar();
  InitColorPanel();
  InitContentWindow();
  InitCanvases();
}


gui::WidgetManager::~WidgetManager() {
  delete m_root;
}


void gui::WidgetManager::Draw(glib::RenderWindow* render_window) {
  assert(render_window != nullptr);

  render_window->Clear(glib::ColorRGBA(1, 1, 1, 1));
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


void gui::WidgetManager::InitMainWindow() {
  m_main_window = MainWindow::GetInstance();
  m_main_window->SetLocation(glib::IntRect(0, 0, APP_WIDTH, APP_HEIGHT));
  m_root = m_main_window;
}


void gui::WidgetManager::InitMainMenu() {
  m_main_menu = MainMenu::GetInstance();
  int main_menu_height = m_skin_manager.GetMainMenuSkin()->m_location.m_size.y;
  m_main_menu->SetLocation(glib::IntRect(0, 0, APP_WIDTH, main_menu_height));
  m_main_menu->SetSkin(m_skin_manager.GetInstance().GetMainMenuSkin());

  assert(m_main_window != nullptr);
  m_main_window->AddMainMenu();
}


void gui::WidgetManager::InitToolBar() {
  m_tool_bar = ToolBar::GetInstance();
  m_tool_bar->SetActiveTool(Brush::GetInstance());
  glib::Text title_text("Tools", m_skin_manager.GetSanFranciscoFont());
  title_text.SetFontSize(FONT_SIZE);
  title_text.SetColor(glib::ColorRGBA(0, 0, 0, 1));

  Title* title = new Title;
  title->SetLocation(glib::IntRect(glib::Vector2i(TOOL_BAR_WIDTH / 2, 0), glib::Vector2i()));
  title->SetText(title_text);

  m_tool_bar->AddTitle(title);

  assert(m_main_window != nullptr);
  assert(m_main_menu   != nullptr);

  m_main_window->AddToolBar();

  int tool_bar_pos_y = m_skin_manager.GetMainMenuSkin()->m_location.m_size.y;
  int tool_bar_height = APP_HEIGHT - tool_bar_pos_y;

  m_tool_bar->SetLocation(glib::IntRect(0, tool_bar_pos_y, TOOL_BAR_WIDTH, tool_bar_height));

  m_content_pos = m_tool_bar->Location().m_position;
  m_content_pos.x += m_tool_bar->Location().m_size.x;
}


void gui::WidgetManager::InitColorPanel() {
  m_color_panel = new SelectPanel;

  ColorSelectButtonSkin*  button_skin = m_skin_manager.GetColorSelectButtonSkin();
  int                           delta = 2 * button_skin->m_hit_area.m_position.x;
  glib::Vector2i        curr_position = button_skin->m_hit_area.m_position;
  glib::Vector2i          button_size = button_skin->m_hit_area.m_size;

  int color_panel_size_y = 2 * delta + button_size.y;

  for (size_t i = 0; i < N_COLORS; ++i) {
    if (i % 5 == 0 && i != 0) {
      curr_position.y += delta + button_size.y;
      color_panel_size_y += delta + button_size.y;
      curr_position.x = button_skin->m_hit_area.m_position.x;
    }
    SelectButton* button = new SelectButton;
    button->SetLocation(glib::IntRect(curr_position, button_size));
    button_skin->m_color = COLORS[i];
    button->SetSkin(button_skin);
    button->SetFunctor(new ColorSelectFunctor(COLORS[i]));
    button->SetOwner(m_color_panel);
    m_color_panel->AddSelectButton(button);

    curr_position.x += delta + button_size.x;
  }
  if (N_COLORS % 5 == 0) {
    color_panel_size_y -= delta;
  }
  m_color_panel->SetLocation(glib::IntRect(0, m_title_bar_height, TOOL_BAR_WIDTH, color_panel_size_y));
  m_tool_bar->AddSelectPanel(m_color_panel);
}


void gui::WidgetManager::InitContentWindow() {
  m_content_main_window = ContentMainWindow::GetInstance();
  m_content_main_window->SetLocation(glib::IntRect(m_content_pos.x,
                                                   m_content_pos.y,
                                                   APP_WIDTH - m_content_pos.x,
                                                   APP_HEIGHT - m_content_pos.y));
  m_main_window->AddContentWindow();
}


void gui::WidgetManager::InitCanvases() {
  m_canvas_window_size = glib::Vector2i(CANVAS_DEFAULT_WIDTH, CANVAS_DEFAULT_HEIGHT + m_title_bar_height);

  glib::Text title_text1("Serega Chernomyrdin", m_skin_manager.GetSanFranciscoFont());
  title_text1.SetFontSize(FONT_SIZE);
  title_text1.SetColor(glib::ColorRGBA(0, 0, 0, 1));

  Canvas* canvas1 = new Canvas(glib::IntRect(0, m_title_bar_height, CANVAS_DEFAULT_WIDTH, CANVAS_DEFAULT_HEIGHT));

  WindowSkin* window_skin = m_skin_manager.GetWindowSkin();
  Window* window1 = new Window;
  window1->SetLocation(glib::IntRect(glib::Vector2i(), m_canvas_window_size));
  window1->SetSkin(window_skin);
  MoveFunctor* window1_move_functor = new MoveFunctor(window1);

  Title* title1 = new Title;
  title1->SetLocation(glib::IntRect(glib::Vector2i(CANVAS_DEFAULT_WIDTH / 2, 0), glib::Vector2i()));
  title1->SetText(title_text1);

  TitleBar* title_bar1 = new TitleBar;
  title_bar1->SetMoveFunctor(window1_move_functor);
  title_bar1->SetSkin(m_skin_manager.GetTitleBarSkin());
  title_bar1->SetLocation(glib::IntRect(glib::Vector2i(0, 0), glib::Vector2i(CANVAS_DEFAULT_WIDTH, m_title_bar_height)));

  CloseWidgetFunctor* close_widget_functor1 = new CloseWidgetFunctor(window1);

  m_button_size  = m_skin_manager.GetCloseButtonSkin()->m_idle_texture_location.m_size;
  m_button_start = glib::Vector2i(CANVAS_DEFAULT_WIDTH - m_skin_manager.GetTitleBarSkin()->m_right_origin_location.m_size.x,
                                  (m_title_bar_height - m_button_size.y) / 2);
  m_button_start.x -= m_button_size.x;

  PlainButton* close_button1 = new PlainButton(glib::IntRect(m_button_start,
                                                             m_button_size),
                                               close_widget_functor1,
                                               m_skin_manager.GetCloseButtonSkin());
  title_bar1->AddCloseButton(close_button1);
  title_bar1->AddTitle(title1);
  window1->AddTitleBar(title_bar1);
  window1->AddContent(canvas1);
  m_content_main_window->AddWindow(window1);
}
