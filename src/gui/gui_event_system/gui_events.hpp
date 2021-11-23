#ifndef GUI_EVENTS_HPP
#define GUI_EVENTS_HPP


#include "glib.hpp"


namespace gui {
  enum class EventType {
    CLOSE,
    LEFT_MOUSE_BUTTON_PRESSED,
    LEFT_MOUSE_BUTTON_RELEASED,
    MOUSE_MOVE,
    LEFT_MOUSE_DRAG,
    RIGHT_MOUSE_DRAG,
    RIGHT_MOUSE_BUTTON_PRESSED,
    RIGHT_MOUSE_BUTTON_RELEASED,
    N_EVENT_TYPES,
    UNDEFINED
  };


  class AbstractEvent {
   protected:
    EventType m_type = EventType::UNDEFINED;
   public:
    AbstractEvent() = default;
    AbstractEvent(EventType event_type);
    virtual ~AbstractEvent() = 0;

    EventType Type() const;
  };


  class MouseButtonEvent: public AbstractEvent {
   public:
    glib::Vector2i m_position;

    MouseButtonEvent() = default;
    MouseButtonEvent(const glib::Vector2i& position);
    virtual ~MouseButtonEvent() = 0;
  };


  class LeftMouseButtonPressedEvent: public MouseButtonEvent {
   public:
    LeftMouseButtonPressedEvent();
    LeftMouseButtonPressedEvent(const glib::Vector2i& position);
    ~LeftMouseButtonPressedEvent() override = default;
  };


  class RightMouseButtonPressedEvent: public MouseButtonEvent {
   public:
    RightMouseButtonPressedEvent();
    RightMouseButtonPressedEvent(const glib::Vector2i& position);
    ~RightMouseButtonPressedEvent() override = default;
  };


  class LeftMouseButtonReleasedEvent: public MouseButtonEvent {
   public:
    LeftMouseButtonReleasedEvent();
    LeftMouseButtonReleasedEvent(const glib::Vector2i& position);
    ~LeftMouseButtonReleasedEvent() override = default;
  };


  class RightMouseButtonReleasedEvent: public MouseButtonEvent {
   public:
    RightMouseButtonReleasedEvent();
    RightMouseButtonReleasedEvent(const glib::Vector2i& position);
    ~RightMouseButtonReleasedEvent() override = default;
  };


  class CloseEvent: public AbstractEvent {
   public:
    CloseEvent();
    ~CloseEvent() override = default;
  };


  class MouseMoveEvent: virtual public AbstractEvent {
   public:
    glib::Vector2i m_new_position;

    MouseMoveEvent();
    MouseMoveEvent(const glib::Vector2i& new_position);
    ~MouseMoveEvent() override = default;
  };


  class LeftMouseDragEvent: public MouseMoveEvent {
   public:
    LeftMouseDragEvent();
    LeftMouseDragEvent(const glib::Vector2i& new_position);
    ~LeftMouseDragEvent() = default;
  };


  class RightMouseDragEvent: public MouseMoveEvent {
   public:
    RightMouseDragEvent();
    RightMouseDragEvent(const glib::Vector2i& new_position);
    ~RightMouseDragEvent() = default;
  };
}


#endif /* gui_events.hpp */
