#ifndef GUI_WINDOW_HPP
#define GUI_WINDOW_HPP


#include "gui_abstract_container_widget.hpp"
#include "gui_title_bar.hpp"


namespace gui {
  class Window: public AbstractContainerWidget {
   protected:
    TitleBar* m_title_bar            = nullptr;
    AbstractWidget* m_content_widget = nullptr;
   public:
    Window() = default;
    Window(const glib::IntRect& location);
    ~Window() = default;

    EventResult OnMouseButtonPressed(glib::Vector2i local_mouse_position,
                                     glib::Vector2i global_mouse_position,
                                     MouseButton button) override;
    EventResult OnMouseButtonReleased(glib::Vector2i local_mouse_position,
                                      glib::Vector2i global_mouse_position,
                                      MouseButton button) override;
    EventResult OnMouseMove(glib::Vector2i new_local_mouse_position,
                            glib::Vector2i new_global_mouse_position) override;

    void Move(const glib::Vector2i& delta_position) override;


    void AddTitleBar(TitleBar* title_bar);
    void AddContent(AbstractWidget* content_widget);
  };
}


#endif /* gui_window.hpp */
