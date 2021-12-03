#ifndef GUI_ABSTRACT_VIEW_SKIN_HPP
#define GUI_ABSTRACT_VIEW_SKIN_HPP


#include "glib.hpp"
#include <cstring>


namespace gui {
  struct AbstractViewSkin {
    AbstractViewSkin() = default;
    virtual ~AbstractViewSkin() = default;

    virtual bool LoadFromFolder(const char* folder_path) = 0;
    virtual AbstractViewSkin* Copy() const = 0;
  };
};


#endif /* gui_abstract_view_skin.hpp */
