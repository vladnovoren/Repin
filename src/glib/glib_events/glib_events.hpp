#ifndef GLIB_EVENTS_HPP
#define GLIB_EVENTS_HPP


#include "SFML/Graphics.hpp"
#include "glib_tools.hpp"


namespace glib {
  enum class MouseButton {
    LEFT,
    RIGHT
  };


  class Event {
   public:
    virtual ~Event() = 0;
  };


  class MouseButtonEvent: public Event {
   protected:
    MouseButton m_button;
    Vector2f m_position;
   public:
    MouseButtonEvent() = default;
    MouseButtonEvent(const MouseButton button, const Vector2f& position);
    virtual ~MouseButtonEvent() = 0;

    void SetType(const MouseButton button);
    void SetPosition(const Vector2f& position);

    MouseButton Button() const;
    Vector2f Position() const;
  };


  class MouseButtonPressedEvent: public MouseButtonEvent {
   public:
    MouseButtonPressedEvent() = default;
    MouseButtonPressedEvent(const MouseButton button,
                            const Vector2f& position);
    ~MouseButtonPressedEvent() override = default;
  };


  class MouseButtonReleasedEvent: public MouseButtonEvent {
   public:
    MouseButtonReleasedEvent() = default;
    MouseButtonReleasedEvent(const MouseButton button,
                             const Vector2f& position);
    ~MouseButtonReleasedEvent() override = default;
  };


  class CloseSysWindowEvent: public Event {
   public:
    ~CloseSysWindowEvent() override = default;
  };

  MouseButton SFMLToGLibMouseButton(const sf::Mouse::Button sf_button);
  MouseButtonEvent* SFMLToGLibMouseButtonEvent(const sf::Event& sf_event);
  Event* SFMLToGLibEvent(const sf::Event& sf_event);
}


#endif /* glib_events.hpp */
