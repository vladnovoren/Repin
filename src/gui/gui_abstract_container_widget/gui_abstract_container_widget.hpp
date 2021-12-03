#ifndef GUI_ABSTRACT_CONTAINER_WIDGET_HPP
#define GUI_ABSTRACT_CONTAINER_WIDGET_HPP


#include "gui_abstract_widget.hpp"
#include <list>


namespace gui {
  class AbstractContainerWidget: public AbstractWidget {
   protected:
    std::list<AbstractWidget*> m_children;
   public:
    void DeleteMatched() override;
  };
}



#endif /* gui_abstract_container_widget.hpp */
