#ifndef GUI_COLOR_PANEL_HPP
#define GUI_COLOR_PANEL_HPP


#include "gui_abstract_container_widget.hpp"
#include "gui_color_select_button.hpp"
#include "gui_color_panel_skin.hpp"


namespace gui {
  class ColorPanel: public AbstractContainerWidget {
   protected:
    ColorPanel() = default;

    ColorPanelSkin* m_skin = nullptr;
   public:
    ~ColorPanel() override;

    static ColorPanel* GetInstance();

    void AddColorSelectButton(ColorSelectButton* color_select_button);
  };
};



#endif /* gui_color_panel.hpp */
