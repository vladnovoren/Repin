#ifndef GUI_TOOL_BAR_HPP
#define GUI_TOOL_BAR_HPP


#include "gui_abstract_container_widget.hpp"
#include "gui_tool_bar_skin.hpp"
#include "gui_brush.hpp"


namespace gui {
  class Brush;
  class ColorPicker;

  class ToolBar: public AbstractContainerWidget {
   private:
    ToolBar();
    ~ToolBar();

    AbstractTool* m_active_tool = nullptr;

    Brush*              m_brush = nullptr;
    // ColorPicker* m_color_picker = nullptr;

    ToolBarSkin*  m_skin = nullptr;
   public:
    static ToolBar* GetInstance();

    bool SetActiveTool(AbstractTool* tool);
    AbstractTool* GetActiveTool() const;

    void SetSkin(ToolBarSkin* skin);

    void Draw(glib::RenderTarget* render_target,
              const glib::Vector2i& position);
  };
}


#endif /* gui_tool_bar.hpp */
