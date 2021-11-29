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

    std::list<AbstractView*> m_mouse_active_views;
   public:
    ~ViewManager();

    void Draw(glib::RenderWindow* render_window);

    static ViewManager& GetInstance();

    AbstractView* GetRoot() const;
    void AddMouseActiveView(AbstractView* view);
    void RemoveMouseActiveView(AbstractView* view);

    EventResult ProcessEvent(glib::RenderWindow* render_window,
                             AbstractView* view);
    EventResult GetAndProcessEvent(glib::RenderWindow* render_window,
                                   AbstractView* view);

    bool IsOpen() const;
  };
}


#endif /* gui_view_manager.hpp */
