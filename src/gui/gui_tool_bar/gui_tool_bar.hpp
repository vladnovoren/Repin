#ifndef GUI_TOOL_BAR_HPP
#define GUI_TOOL_BAR_HPP


#include "gui_abstract_container_widget.hpp"
#include "gui_abstract_tool.hpp"
#include "gui_tool_bar_skin.hpp"


namespace gui {
  class Brush;

  class ToolBar: public AbstractContainerWidget {
   private:
    ToolBar();
    ~ToolBar();

    AbstractTool* m_active_tool = nullptr;
    
    ToolBarSkin*  m_skin = nullptr;
   public:
    static ToolBar* GetInstance();

    bool SetActiveTool(AbstractTool* tool);
    AbstractTool* GetActiveTool() const;

    void SetSkin(ToolBarSkin* skin);

    void AddBrush(Brush* brush);

    void Draw(glib::RenderTarget* render_target,
              const glib::Vector2i& position);
  };
}


#endif /* gui_tool_bar.hpp */
