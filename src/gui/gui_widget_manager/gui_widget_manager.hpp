#ifndef GUI_WIDGET_MANAGER_HPP
#define GUI_WIDGET_MANAGER_HPP


#include "gui_abstract_widget.hpp"
#include "gui_skin_manager.hpp"
#include "gui_plain_button.hpp"
#include "gui_events.hpp"
#include "gui_title_bar.hpp"
#include "gui_window.hpp"
#include "gui_canvas.hpp"
#include "gui_main_menu.hpp"
#include "gui_main_window.hpp"
#include "gui_tool_bar.hpp"
#include "gui_brush.hpp"
#include "gui_select_button.hpp"
#include "gui_select_panel.hpp"
#include "gui_content_window.hpp"
#include "gui_color_select_functor.hpp"


namespace gui {
  class WidgetManager {
   protected:
    WidgetManager();

    AbstractWidget* m_root = nullptr;

    bool m_is_open = true;

    AbstractWidget* m_mouse_active_widget = nullptr;

    SkinManager&              m_skin_manager = SkinManager::GetInstance();
    MainMenu*                    m_main_menu = nullptr;
    ToolBar*                      m_tool_bar = nullptr;
    ColorPicker*              m_color_picker = nullptr;
    SelectPanel*               m_color_panel = nullptr;
    SelectPanel*               m_tools_panel = nullptr;
    MainWindow*                m_main_window = nullptr;
    ContentMainWindow* m_content_main_window = nullptr;

    glib::Vector2i m_content_pos;
    glib::Vector2i m_canvas_window_size;
    int            m_title_bar_height = m_skin_manager.GetTitleBarSkin()->m_left_origin_location.m_size.y;
    glib::Vector2i m_button_size;
    glib::Vector2i m_button_start;
   public:
    ~WidgetManager();

    void Draw(glib::RenderWindow* render_window);

    static WidgetManager& GetInstance();

    AbstractWidget* GetRoot();
    AbstractWidget* GetMouseActiveWidget();

    void AddMouseActiveWidget(AbstractWidget* widget);
    void RemoveMouseActiveWidget(AbstractWidget* widget);

    void DeleteMatched();

    EventResult ProcessEvent(AbstractWidget* widget, const sf::Event& sf_event,
                             bool force = false);
    EventResult GetAndProcessEvent(glib::RenderWindow* render_window,
                                   bool& is_pooled);
    EventResult ProcessMouseEventOnSignedWidget(glib::RenderWindow* render_window,
                                              const sf::Event& sf_event);

    bool IsOpen() const;


    void InitMainWindow();
    void InitMainMenu();
    void InitToolBar();
    void InitColorPanel();
    void InitContentWindow();
    void InitCanvases();
  };
}


#endif /* gui_widget_manager.hpp */
