#ifndef GUI_ABSTRACT_VIEW_FUNCTOR_HPP
#define GUI_ABSTRACT_VIEW_FUNCTOR_HPP


#include "gui_abstract_view.hpp"


namespace gui {
  class AbstractViewFunctor {
   public:
    AbstractViewFunctor() = default;
    virtual ~AbstractViewFunctor() = 0;

    virtual void operator()() = 0;
  };


  class CloseViewFunctor: public AbstractViewFunctor {
   protected:
    AbstractView* m_view;
   public:
    CloseViewFunctor(AbstractView* view);

    void operator()() override;
  };
}


#endif /* gui_abstract_view_functor.hpp */
