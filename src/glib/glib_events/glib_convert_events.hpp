#ifndef GLIB_CONVERT_EVENTS_HPP
#define GLIB_CONVERT_EVENTS_HPP


#include "glib_events.hpp"


namespace glib {
  glib::Event* SFMLToGLibEvent(const sf::Event& sf_event);

  glib::MouseButtonEvent* SFMLToGLibMouseButtonEvent(const sf::Event& sf_mouse_button_event);
  glib::MouseMoveEvent* SFMLToGLibMouseMoveEvent(const sf::Event& sf_mouse_move_event);
}


#endif /* glib_convert_events.hpp */
