#ifndef GUI_ABSTRACT_VIEW_HPP
#define GUI_ABSTRACT_VIEW_HPP


#include "glib.hpp"
#include "gui_event_keeper.hpp"
#include <list>


namespace gui {
  class AbstractView: public EventKeeper {
   protected:
    glib::FloatRect m_location;
    std::list<AbstractView*> m_children;

    bool m_should_close = false;
   public:
    AbstractView() = default;
    AbstractView(const glib::FloatRect& location);
    virtual ~AbstractView() = 0;

    void SetLocation(const glib::FloatRect& location);
    glib::FloatRect Location() const;

    virtual bool IsMouseInside(const glib::Vector2f& mouse_position);

    virtual EventResult OnLeftMouseButtonPressed(const glib::Vector2f& mouse_position);
    virtual EventResult OnRightMouseButtonPressed(const glib::Vector2f& mouse_position);

    virtual EventResult OnLeftMouseButtonReleased(const glib::Vector2f& mouse_position);
    virtual EventResult OnRightMouseButtonReleased(const glib::Vector2f& mouse_position);

    EventResult OnClose();

    void MatchForClose();
  };
}


#endif /* gui_abstract_view.hpp */
