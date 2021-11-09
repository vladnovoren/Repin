#ifndef GUI_ABSTRACT_VIEW_FUNCTOR_HPP
#define GUI_ABSTRACT_VIEW_FUNCTOR_HPP


#include "gui_abstract_view.hpp"


namespace gui {
  template<typename ...TParams>
  class AbstractViewFunctor {
    using TMethod = EventResult(AbstractView::*)(TParams...);
    AbstractView* m_view = nullptr;
    TMethod m_method = nullptr;
   public:
    AbstractViewFunctor(AbstractView* view, TMethod method):
    m_view(view), m_method(method) {
      assert(m_view);
      assert(m_method);
    }

    EventResult operator()(TParams... params) {
      return (m_view->*m_method)(params);
    }
  };
}



#endif /* gui_abstract_view_functor.hpp */