#ifndef GUI_WINDOW_HPP
#define GUI_WINDOW_HPP


#include "gui_elem.hpp"


namespace gui {
  class Window: public Elem {
   protected:
    glib::RenderTexture m_render_texture;
   public:
    Window() = default;
    Window(const glib::FloatRect& location,
           const glib::RenderTexture& render_texture);
    ~Window() = default;
  };
}


#endif /* gui_window.hpp */
