#ifndef WINDOW_HPP
#define WINDOW_HPP


#include "GUIElem.hpp"


namespace GUI {
  class Window: public GUIElem {
  public:
    Window();
    Window(const glib::IntRect& location);
    ~Window();

    void Render();
  };
};


#endif /* window.hpp */
