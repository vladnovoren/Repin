#ifndef GUI_EVENTS_HPP
#define GUI_EVENTS_HPP


#include <list>


template<class ...TParams>
class AbstractEventHandler {
 public:
  virtual void Process(TParams... params) = 0;
};


template<class ...TParams>
class TEvent {
 protected:
  using TEventHandler = AbstractEventHandler<TParams...>;
  std::list<TEventHandler*> handlers_list;
 public:
 TEvent() = default;
  ~TEvent() {
    for (auto handler_ptr: handlers_list) {
      delete handler_ptr;
    }
  }

  void operator()(TParams... params) {
    for (auto handler_ptr: handlers_list) {
      handler_ptr->Process(params...);
    }
  }

  typename std::list<TEventHandler*>::iterator FindHandler(TEventHandler* event_handler) {
    for (auto it = handlers_list.begin(); it != handlers_list.end(); ++it) {
      if (**it == *event_handler) {
        return it;
      }
    }
    return handlers_list->end();
  }

  typename std::list<TEventHandler*>::iterator AddHandler(TEventHandler* event_handler) {
    auto found = FindHandler(event_handler);
    if (found != handlers_list.end()) {
      return handlers_list.insert(event_handler);
    } else {
      return found;
    }
  }

  bool EraseHandler(TEventHandler* event_handler) {
    auto found = FindHandler(event_handler);
    if (found == handlers_list.end()) {
      return false;
    } else {
      handlers_list.erase(found);
      return true;
    }
  }
};


template<class TObject, class ...TParams>
class TEventHandler: public AbstractEventHandler<TParams...> {
 protected:
  using TMethod = void(TObject::*)(TParams...);
  TObject* m_object;
  TMethod m_method;
 public:
   TEventHandler(TObject* object, TMethod method):
   m_object(object), m_method(method) {}

  void Process(TParams... params) {
    (m_object->*m_method)(params...);
  }

  bool operator==(const TEventHandler<TObject, TParams...>& other) {
    return this->m_object == other->m_object &&
           this->m_method == other->m_method;
  }

  bool operator!=(const TEventHandler<TObject, TParams...>& other) {
    return !(*this == other);
  }
};


#endif /* gui_events.hpp */