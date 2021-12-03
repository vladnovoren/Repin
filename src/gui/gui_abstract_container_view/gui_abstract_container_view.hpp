#ifndef GUI_ABSTRACT_CONTAINER_VIEW_HPP
#define GUI_ABSTRACT_CONTAINER_VIEW_HPP


#include "gui_abstract_view.hpp"
#include <list>


namespace gui {
  class AbstractContainerView: public AbstractView {
   protected:
    std::list<AbstractView*> m_children;
  };
}



#endif /* gui_abstract_container_view.hpp */
