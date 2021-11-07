#ifndef GUI_VIEW_HPP
#define GUI_VIEW_HPP


#include "glib.hpp"
#include "glib_tools.hpp"
#include <list>


namespace gui {
  class View {
   protected:
    glib::FloatRect m_location;
    std::list<View*> m_children;

    bool m_should_close = false;
   public:
    View() = default;
    View(const glib::FloatRect& location);
    virtual ~View() = 0;

    void SetLocation(const glib::FloatRect& location);

    glib::FloatRect Location() const;

    virtual bool IsMouseInside(const glib::Vector2f& mouse_position) = 0;
  };
}


#endif /* gui_view.hpp */
