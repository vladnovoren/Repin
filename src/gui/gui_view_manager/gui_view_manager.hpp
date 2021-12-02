#ifndef GUI_VIEW_MANAGER_HPP
#define GUI_VIEW_MANAGER_HPP


#include "gui_abstract_view.hpp"
#include "gui_skin_manager.hpp"
#include "gui_button.hpp"
#include "gui_events.hpp"
#include "gui_title_bar.hpp"


namespace gui {
  class ViewManager {
   protected:
    ViewManager();

    AbstractView* m_root = nullptr;
    SkinManager   m_skin_manager;

    bool is_open = true;

    AbstractView* m_mouse_active_view = nullptr;
   public:
    ~ViewManager();

    void Draw(glib::RenderWindow* render_window);

    static ViewManager& GetInstance();

    AbstractView* GetRoot() const;
    void AddMouseActiveView(AbstractView* view);
    void RemoveMouseActiveView(AbstractView* view);

    EventResult ProcessEvent(AbstractView* view, const sf::Event& sf_event,
                             bool force = false);
    EventResult GetAndProcessEvent(glib::RenderWindow* render_window, bool& is_pooled);
    EventResult ProcessMouseEventOnSignedView(glib::RenderWindow* render_window,
                                              const sf::Event& sf_event);

    bool IsOpen() const;
  };
}


#endif /* gui_view_manager.hpp */
