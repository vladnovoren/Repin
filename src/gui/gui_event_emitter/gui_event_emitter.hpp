#ifndef GUI_EVENT_EMITTER_HPP
#define GUI_EVEMT_EMITTER_HPP


#include "glib_convert_events.hpp"
#include "gui_abstract_view.hpp"
#include "gui_events.hpp"


namespace gui {
  class EventEmitter {
   private:
    EventEmitter();
   protected:
    using EmitterFunc = EventResult(EventEmitter::*)(gui::AbstractEvent*, AbstractView*);
    EmitterFunc emitter_funcs[size_t(gui::EventType::N_EVENT_TYPES)] = {};
   public:
    static EventEmitter& GetInstance();

    EventResult Emit(gui::AbstractEvent* event, AbstractView* view);

    EventResult EmitClose                   (gui::AbstractEvent* event, AbstractView* view);
    EventResult EmitLeftMouseButtonPressed  (gui::AbstractEvent* event, AbstractView* view);
    EventResult EmitRightMouseButtonPressed (gui::AbstractEvent* event, AbstractView* view);
    EventResult EmitLeftMouseButtonReleased (gui::AbstractEvent* event, AbstractView* view);
    EventResult EmitRightMouseButtonReleased(gui::AbstractEvent* event, AbstractView* view);
    EventResult EmitMouseMove               (gui::AbstractEvent* event, AbstractView* view);
    EventResult EmitLeftMouseDrag           (gui::AbstractEvent* event, AbstractView* view);
    EventResult EmitRightMouseDrag          (gui::AbstractEvent* event, AbstractView* view);
  };
}


#endif /* gui_event_emitter.hpp */
