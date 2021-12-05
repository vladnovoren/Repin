#ifndef GUI_WINDOW_HPP
#define GUI_WINDOW_HPP


#include "gui_abstract_widget.hpp"
#include "gui_title_bar.hpp"
#include "gui_abstract_widget_skin.hpp"


namespace gui {
  class Window: public AbstractWidget {
   protected:
    TitleBar* m_title_bar = nullptr;
   public:
    Window() = default;
    Window(DefaultWidgetSkin* skin);
    ~Window() = default;

    EventResult OnMouseButtonPressed(glib::Vector2i mouse_position, MouseButton button) override;
    EventResult OnMouseMove(glib::Vector2i mouse_position, MouseButton button) override;

    void AddTitleBar(TitleBar* title_bar);
  };
}


#endif /* gui_window.hpp */
