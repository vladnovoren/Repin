#ifndef GUI_VIEW_HPP
#define GUI_VIEW_HPP


#include "glib.hpp"


namespace gui {
  class View {
   protected:
    glib::FloatRect m_location;
   public:
    View() = default;
    View(const glib::FloatRect& location);
    virtual ~View() = 0;

    void SetLocation(const glib::FloatRect& location);

    glib::FloatRect Location() const;

    void OnClose();

    void OnLeftMouseButtonPressed();
    void OnRightMouseButtonPressed();

    void OnLeftMouseButtonReleased();
    void OnRightMouseButtonReleased();
  };
}


#endif /* gui_view.hpp */