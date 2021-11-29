#ifndef GUI_EVENTS_HPP
#define GUI_EVENTS_HPP


#include "glib.hpp"
#include "gui_abstract_view.hpp"


namespace gui {
  MouseButton SFMLToGUIMouseButton(sf::Mouse::Button sf_button);

  bool IsMouseEvent(sf::Event sf_event);
}


#endif /* gui_events.hpp */
