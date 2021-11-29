#include "gui_abstract_event_spreader.hpp"


gui::AbstractEventSpreader::~AbstractEventSpreader() = default;


gui::EventResult gui::AbstractEventSpreader::SpreadEventDFS(AbstractEvent* event,
                                                            AbstractView* view) {
  assert(event != nullptr);
  assert(view != nullptr);

  EventResult event_result      = EventResult::NOT_PROCESSED;
  EventResult curr_event_result = EventResult::NOT_PROCESSED;
  EventEmitter& event_emitter_instance = EventEmitter::GetInstance();
  for (auto child_it = view->m_children.begin();
       child_it != view->m_children.end();
       ++child_it) {
    auto child_ptr = *child_it;
    assert(child_ptr != nullptr);
    curr_event_result = event_emitter_instance.Emit(event, child_ptr);
    switch (curr_event_result) {
      case EventResult::PROCESSED_NOT_FINAL:
        event_result = EventResult::PROCESSED_NOT_FINAL;
        break;
      case EventResult::PROCESSED_FINAL:
        return EventResult::PROCESSED_FINAL;
      default:
        break;
    }
  }
  curr_event_result = event_emitter_instance.Emit(event, view);
  switch (curr_event_result) {
    case EventResult::PROCESSED_NOT_FINAL:
      event_result = EventResult::PROCESSED_NOT_FINAL;
      break;
    case EventResult::PROCESSED_FINAL:
      event_result = EventResult::PROCESSED_FINAL;
    default:
      break;
  }
  return event_result;
}


gui::EventResult gui::AbstractEventSpreader::SpreadClose(AbstractEvent* event,
                                                         AbstractView* view) {
  return SpreadEventDFS(event, view);
}


gui::EventResult gui::AbstractEventSpreader::SpreadLeftMouseButtonPressed(AbstractEvent* event,
                                                                          AbstractView* view){
  return SpreadEventDFS(event, view);
}


gui::EventResult gui::AbstractEventSpreader::SpreadRightMouseButtonPressed(AbstractEvent* event,
                                                                           AbstractView* view){
  return SpreadEventDFS(event, view);
}


gui::EventResult gui::AbstractEventSpreader::SpreadLeftMouseButtonReleased(AbstractEvent* event,
                                                                           AbstractView* view){
  return SpreadEventDFS(event, view);
}


gui::EventResult gui::AbstractEventSpreader::SpreadRightMouseButtonReleased(AbstractEvent* event,
                                                                            AbstractView* view){
  return SpreadEventDFS(event, view);
}


gui::EventResult gui::AbstractEventSpreader::SpreadMouseMove(AbstractEvent* event,
                                                             AbstractView* view){
  return SpreadEventDFS(event, view);
}


gui::EventResult gui::AbstractEventSpreader::SpreadLeftMouseDrag(AbstractEvent* event,
                                                                 AbstractView* view){
  return SpreadEventDFS(event, view);
}


gui::EventResult gui::AbstractEventSpreader::SpreadRightMouseDrag(AbstractEvent* event,
                                                                  AbstractView* view){
  return SpreadEventDFS(event, view);
}
