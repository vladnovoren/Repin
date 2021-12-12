#include "gui_tool_bar.hpp"
#include "gui_brush.hpp"
#include "gui_skin_manager.hpp"


gui::ToolBar::ToolBar() {
  SetSkin(SkinManager::GetInstance().GetToolBarSkin());
}


gui::ToolBar::~ToolBar() {
  delete m_skin;
}


gui::ToolBar* gui::ToolBar::GetInstance() {
  static ToolBar* instance = new ToolBar;
  return instance;
}


bool gui::ToolBar::SetActiveTool(AbstractTool* tool) {
  auto found_it = std::find(m_children.begin(), m_children.end(), tool);
  if (found_it == m_children.end()) {
    printf("Unable to set tool as active: it doesn't belong to toolbar\n");
    return false;
  }
  m_active_tool = tool;
  return true;
}


gui::AbstractTool* gui::ToolBar::GetActiveTool() const {
  assert(m_active_tool != nullptr);
  return m_active_tool;
}


void gui::ToolBar::SetSkin(ToolBarSkin* skin) {
  assert(skin != nullptr);

  delete m_skin;
  m_skin = new ToolBarSkin(*skin);
}


void gui::ToolBar::AddBrush(Brush* brush) {
  assert(brush != nullptr);

  brush->m_parent_widget = this;
  AddChild(brush);
}


void gui::ToolBar::Draw(glib::RenderTarget* render_target,
                        const glib::Vector2i& position) {
  assert(render_target != nullptr);

  if (m_needs_to_render) {
    m_skin->Render(m_location.m_size);
    m_needs_to_render = false;
  }
  glib::Vector2i position_to_copy = position + m_location.m_position;
  m_skin->CopyToRenderTarget(render_target, position_to_copy);
}
