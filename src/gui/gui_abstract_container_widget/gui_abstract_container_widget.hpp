#ifndef GUI_ABSTRACT_CONTAINER_WIDGET_HPP
#define GUI_ABSTRACT_CONTAINER_WIDGET_HPP


#include "gui_abstract_widget.hpp"
#include <list>


namespace gui {
  class AbstractContainerWidget: public AbstractWidget {
   protected:
    std::list<AbstractWidget*> m_children;
   public:
    AbstractContainerWidget() = default;
    AbstractContainerWidget(const glib::IntRect& location);
    virtual ~AbstractContainerWidget() = 0;

    void DeleteMatched() override;
  };
}


#endif /* gui_abstract_container_widget.hpp */
