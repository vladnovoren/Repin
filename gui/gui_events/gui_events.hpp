#ifndef GUI_EVENTS
#define GUI_EVENTS


#include "glib_events.hpp"
#include "gui_view.hpp"


namespace gui {
  class Event {
   public:
    virtual ~Event() = 0;

    virtual void Process(View* view) = 0;
  };


  class CloseEvent: public Event {
   public:
    ~CloseEvent() override = default;

    void Process(View* view) override;
  };


  class MouseButtonEvent: public Event {
   protected:
    glib::MouseButtonEvent* m_sf_mouse_button_event;
   public:
    MouseButtonEvent(glib::MouseButtonEvent* sf_mouse_button_event);
    ~MouseButtonEvent() override = default;
  };


  class MouseButtonPressedEvent: public MouseButtonEvent {
   public:
    MouseButtonPressedEvent(glib::MouseButtonPressedEvent* sf_mouse_button_pressed_event);
    ~MouseButtonPressedEvent() override = default;

    void Process(View* view) override;
  };


  class MouseButtonReleasedEvent: public MouseButtonEvent {
   public:
    MouseButtonReleasedEvent(glib::MouseButtonReleasedEvent* sf_mouse_button_released_event);
    ~MouseButtonReleasedEvent() override = default;

    void Process(View* view) override;
  };
}



#endif /* gui_events.hpp */