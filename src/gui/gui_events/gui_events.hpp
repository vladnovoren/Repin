#ifndef GUI_EVENTS_HPP
#define GUI_EVENTS_HPP


#include <list>


namespace gui {
  enum class EventResult {
    PROCESSED_NOT_ALL,
    PROCESSED_ALL,
    REJECTED
  };


  // class AbstractEvent {
  // public:
  //   AbstractEvent() = default;
  //   virtual ~AbstractEvent() = 0;
  // };


  // AbstractEvent::~AbstractEvent() = default;
}


#endif /* gui_events.hpp */
