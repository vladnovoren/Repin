#ifndef GUI_WINDOW_HPP
#define GUI_WINDOW_HPP


#include "gui_abstract_view.hpp"
#include "gui_title_bar.hpp"


namespace gui {
  class Window: public AbstractView {
   protected:
    TitleBar* title_bar;    
   public:
    Window() = default;
    Window(const glib::FloatRect& location);
    ~Window() = default;
  };
}


#endif /* gui_window.hpp */
