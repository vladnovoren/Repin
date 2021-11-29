#ifndef GUI_CONVERT_EVENTS_FROM_GLIB_HPP
#define GUI_CONVERT_EVENTS_FROM_GLIB_HPP


#include "gui_events.hpp"


namespace gui {
  AbstractEvent*    GLibToGUIEvent(const glib::Event* glib_event);

  MouseButtonEvent* GLibToGUIMouseButtonEvent(const glib::Event* glib_event);
  MouseMoveEvent*   GLibToGUIMouseMoveEvent(const glib::Event* glib_event);
}


#endif /* gui_convert_events_from_glib.hpp */
