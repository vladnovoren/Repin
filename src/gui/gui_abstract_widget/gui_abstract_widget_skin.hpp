#ifndef GUI_ABSTRACT_WIDGET_SKIN_HPP
#define GUI_ABSTRACT_WIDGET_SKIN_HPP


#include "glib.hpp"
#include <cstring>


namespace gui {
  struct AbstractWidgetSkin {
    AbstractWidgetSkin() = default;
    virtual ~AbstractWidgetSkin() = default;

    virtual bool LoadFromFolder(const char* folder_path) = 0;
    virtual AbstractWidgetSkin* Copy() const = 0;
  };
};


#endif /* gui_abstract_widget_skin.hpp */
