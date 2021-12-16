#ifndef GUI_COLOR_PANEL_HPP
#define GUI_COLOR_PANEL_HPP


#include "gui_abstract_container_widget.hpp"
#include "gui_color_select_button.hpp"


namespace gui {
  class ColorPanel: public AbstractContainerWidget {
    friend class ColorSelectButtonFunctor;
   protected:
    ColorPanel() = default;
   public:
    ~ColorPanel() override = default;

    static ColorPanel* GetInstance();

    void AddColorSelectButton(ColorSelectButton* color_select_button);
  };
};



#endif /* gui_color_panel.hpp */
