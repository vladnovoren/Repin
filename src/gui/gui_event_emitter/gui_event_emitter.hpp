#ifndef GUI_EVENT_EMITTER_HPP
#define GUI_EVEMT_EMITTER_HPP


#include "glib_convert_events.hpp"
#include "gui_abstract_widget.hpp"
#include "gui_events.hpp"


namespace gui {
  class EventEmitter {
   private:
    EventEmitter();
   protected:
    using EmitterFunc = EventResult(EventEmitter::*)(gui::AbstractEvent*, AbstractWidget*);
    EmitterFunc emitter_funcs[size_t(gui::EventType::N_EVENT_TYPES)] = {};
   public:
    static EventEmitter& GetInstance();

    EventResult Emit(gui::AbstractEvent* event, AbstractWidget* widget);

    EventResult EmitClose                   (gui::AbstractEvent* event, AbstractWidget* widget);
    EventResult EmitLeftMouseButtonPressed  (gui::AbstractEvent* event, AbstractWidget* widget);
    EventResult EmitRightMouseButtonPressed (gui::AbstractEvent* event, AbstractWidget* widget);
    EventResult EmitLeftMouseButtonReleased (gui::AbstractEvent* event, AbstractWidget* widget);
    EventResult EmitRightMouseButtonReleased(gui::AbstractEvent* event, AbstractWidget* widget);
    EventResult EmitMouseMove               (gui::AbstractEvent* event, AbstractWidget* widget);
    EventResult EmitLeftMouseDrag           (gui::AbstractEvent* event, AbstractWidget* widget);
    EventResult EmitRightMouseDrag          (gui::AbstractEvent* event, AbstractWidget* widget);
  };
}


#endif /* gui_event_emitter.hpp */
