#ifndef GUI_VIEW_MANAGER_HPP
#define GUI_VIEW_MANAGER_HPP


#include "gui_abstract_view.hpp"
#include "gui_event_emitter.hpp"


namespace gui {
  class ViewManager {
   protected:
    AbstractView* m_root = nullptr;
    EventEmitter m_event_emitter;
   public:
    ViewManager();
    ~ViewManager();

    void Draw(glib::RenderWindow* render_window);
    void Emit(glib::Event* event);
  };
}


#endif /* gui_view_manager.hpp */