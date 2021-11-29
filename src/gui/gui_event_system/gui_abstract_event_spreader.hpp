#ifndef GUI_ABSTRACT_EVENT_SPREADER_HPP
#define GUI_ABSTRACT_EVENT_SPREADER_HPP


#include "gui_abstract_view.hpp"
#include "gui_event_emitter.hpp"
#include "gui_events.hpp"


namespace gui {
  class AbstractEventSpreader {
   protected:
   public:
    AbstractEventSpreader() = default;
    virtual ~AbstractEventSpreader() = 0;

    EventResult SpreadEventDFS                        (AbstractEvent* event, AbstractView* view);

    virtual EventResult SpreadClose                   (AbstractEvent* event, AbstractView* view);
    virtual EventResult SpreadLeftMouseButtonPressed  (AbstractEvent* event, AbstractView* view);
    virtual EventResult SpreadRightMouseButtonPressed (AbstractEvent* event, AbstractView* view);
    virtual EventResult SpreadLeftMouseButtonReleased (AbstractEvent* event, AbstractView* view);
    virtual EventResult SpreadRightMouseButtonReleased(AbstractEvent* event, AbstractView* view);
    virtual EventResult SpreadMouseMove               (AbstractEvent* event, AbstractView* view);
    virtual EventResult SpreadLeftMouseDrag           (AbstractEvent* event, AbstractView* view);
    virtual EventResult SpreadRightMouseDrag          (AbstractEvent* event, AbstractView* view);
  };
}


#endif /* gui_abstract_event_spreader.hpp */
