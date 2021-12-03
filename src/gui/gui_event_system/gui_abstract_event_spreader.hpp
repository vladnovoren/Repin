#ifndef GUI_ABSTRACT_EVENT_SPREADER_HPP
#define GUI_ABSTRACT_EVENT_SPREADER_HPP


#include "gui_abstract_widget.hpp"
#include "gui_event_emitter.hpp"
#include "gui_events.hpp"


namespace gui {
  class AbstractEventSpreader {
   protected:
   public:
    AbstractEventSpreader() = default;
    virtual ~AbstractEventSpreader() = 0;

    EventResult SpreadEventDFS                        (AbstractEvent* event, AbstractWidget* widget);

    virtual EventResult SpreadClose                   (AbstractEvent* event, AbstractWidget* widget);
    virtual EventResult SpreadLeftMouseButtonPressed  (AbstractEvent* event, AbstractWidget* widget);
    virtual EventResult SpreadRightMouseButtonPressed (AbstractEvent* event, AbstractWidget* widget);
    virtual EventResult SpreadLeftMouseButtonReleased (AbstractEvent* event, AbstractWidget* widget);
    virtual EventResult SpreadRightMouseButtonReleased(AbstractEvent* event, AbstractWidget* widget);
    virtual EventResult SpreadMouseMove               (AbstractEvent* event, AbstractWidget* widget);
    virtual EventResult SpreadLeftMouseDrag           (AbstractEvent* event, AbstractWidget* widget);
    virtual EventResult SpreadRightMouseDrag          (AbstractEvent* event, AbstractWidget* widget);
  };
}


#endif /* gui_abstract_event_spreader.hpp */
