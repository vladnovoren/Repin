#ifndef GUI_TITLE_HPP
#define GUI_TITLE_HPP


#include "gui_abstract_widget.hpp"


namespace gui {
  class Title: public AbstractWidget {
   protected:
    glib::Text m_text;
   public:
    Title() = default;
    Title(const char* label, const glib::Vector2i& center_position,
          unsigned int font_size);
    ~Title() = default;

    void SetLabel(const char* label);
    void SetCenterPosition(const glib::Vector2i& center_position);
    void SetFontSize(unsigned int font_size);
  };
}


#endif /* gui_title.hpp */
