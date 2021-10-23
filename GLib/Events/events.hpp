#ifndef GLIB_EVENTS_HPP
#define GLIB_EVENTS_HPP

#include "SFML/Graphics.hpp"
#include "tools.hpp"


namespace glib {
  enum class MouseButton {
    UNDEFINED,
    LEFT,
    RIGHT
  };

  MouseButton ToMyMouseButton(sf::Mouse::Button sf_button);

  struct Event {
    enum class EventType {
      UNDEFINED,
      MOUSE_BUTTON_PRESSED,
      MOUSE_BUTTON_RELEASED,
      CLOSED
    };

    struct MouseButtonEvent {
      MouseButton button;
      tls::Vector2f position;
    };

    EventType type;
    union {
      MouseButtonEvent mouse_button;
    };
  };

  Event::MouseButtonEvent ToMyMouseButtonEvent(const sf::Event::MouseButtonEvent& sf_mouse_button_event);
  Event ToMyEvent(const sf::Event& sf_event);
}


#endif /* events.hpp */