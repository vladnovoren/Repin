#ifndef GLIB_EVENTS_HPP
#define GLIB_EVENTS_HPP


#include "SFML/Graphics.hpp"
#include "glib_tools.hpp"


namespace glib {
  enum class EventType {
    UNDEFINED,
    LEFT_MOUSE_BUTTON_PRESSED,
    LEFT_MOUSE_BUTTON_RELEASED,
    RIGHT_MOUSE_BUTTON_PRESSED,
    RIGHT_MOUSE_BUTTON_RELEASED,
    CLOSE_SYS_WINDOW
  };


  class Event {
   protected:
    EventType m_type = EventType::UNDEFINED;
   public:
    Event() = default;
    Event(EventType type);
    virtual ~Event() = 0;

    EventType Type() const;
  };


  class MouseButtonEvent: public Event {
   public:
    Vector2f m_position;

    MouseButtonEvent() = default;
    MouseButtonEvent(EventType type);
    MouseButtonEvent(EventType type, const Vector2f& position);
    virtual ~MouseButtonEvent() = 0;
  };


  class LeftMouseButtonPressedEvent: public MouseButtonEvent {
   public:
    LeftMouseButtonPressedEvent();
    LeftMouseButtonPressedEvent(const Vector2f& position);
    ~LeftMouseButtonPressedEvent() override = default;
  };


  class RightMouseButtonPressedEvent: public MouseButtonEvent {
   public:
    RightMouseButtonPressedEvent();
    RightMouseButtonPressedEvent(const Vector2f& position);
    ~RightMouseButtonPressedEvent() override = default;
  };


  class LeftMouseButtonReleasedEvent: public MouseButtonEvent {
   public:
    LeftMouseButtonReleasedEvent();
    LeftMouseButtonReleasedEvent(const Vector2f& position);
    ~LeftMouseButtonReleasedEvent() override = default;
  };


  class RightMouseButtonReleasedEvent: public MouseButtonEvent {
   public:
    RightMouseButtonReleasedEvent();
    RightMouseButtonReleasedEvent(const Vector2f& position);
    ~RightMouseButtonReleasedEvent() override = default;
  };


  class CloseSysWindowEvent: public Event {
   public:
    CloseSysWindowEvent();
    ~CloseSysWindowEvent() override = default;
  };
}


#endif /* glib_events.hpp */
