#ifndef GUI_WINDOW_HPP
#define GUI_WINDOW_HPP


#include "gui_abstract_view.hpp"
#include "gui_title_bar.hpp"
#include "gui_default_view_skin.hpp"


namespace gui {
  class Window: public AbstractView {
   protected:
    DefaultViewSkin* m_skin = nullptr;
    TitleBar* m_title_bar = nullptr;
   public:
    Window() = default;
    Window(DefaultViewSkin* skin, TitleBar* title_bar);
    ~Window() = default;

    void OnLeftMouseDrag(glib::Vector2i new_mouse_position) override;
    void OnRightMouseDrag(glib::Vector2i new_mouse_position) override;

    void OnMouseHoverBegin(glib::Vector2i mouse_position) override;
    void OnMouseHoverEnd(glib::Vector2i mouse_position) override;
  };
}


#endif /* gui_window.hpp */
