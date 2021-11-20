#ifndef GUI_ABSTRACT_VIEW_FUNCTOR_HPP
#define GUI_ABSTRACT_VIEW_FUNCTOR_HPP


#include "gui_abstract_view.hpp"


namespace gui {
  class AbstractFunctor {
   public:
    AbstractFunctor() = default;
    virtual ~AbstractFunctor() = 0;

    virtual void operator()() = 0;
  };

  AbstractFunctor::~AbstractFunctor() = default;


  class CloseViewFunctor: public AbstractFunctor {
   protected:
    AbstractView* m_view;
   public:
    CloseViewFunctor(AbstractView* view): m_view(view) {
      assert(m_view);
    }

    void operator()() override {
      return m_view->OnClose();
    }
  };
}



#endif /* gui_abstract_view_functor.hpp */
