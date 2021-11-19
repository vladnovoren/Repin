#ifndef GUI_EVENT_EMITTER_HPP
#define GUI_EVEMT_EMITTER_HPP


#include "glib_convert_events.hpp"
#include "gui_abstract_view.hpp"


namespace gui {
  class EventEmitter {
   protected:
    using EmitterFunc = void(EventEmitter::*)(glib::Event*, AbstractView*);
    EmitterFunc emitter_funcs[size_t(glib::EventType::N_EVENT_TYPES)] = {};
   public:
    EventEmitter();

    void Emit(glib::Event* event, AbstractView* view);

    void EmitClose                   (glib::Event* event, AbstractView* view);
    void EmitLeftMouseButtonPressed  (glib::Event* event, AbstractView* view);
    void EmitRightMouseButtonPressed (glib::Event* event, AbstractView* view);
    void EmitLeftMouseButtonReleased (glib::Event* event, AbstractView* view);
    void EmitRightMouseButtonReleased(glib::Event* event, AbstractView* view);
  };
}


#endif /* gui_event_emitter.hpp */
