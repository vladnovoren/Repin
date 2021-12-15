#include "gui_set_brush_functor.hpp"


void gui::SetBrushFunctor::operator()() {
  ToolBar* tool_bar = ToolBar::GetInstance();
  assert(tool_bar != nullptr);

  Brush* brush = Brush::GetInstance();
  assert(brush != nullptr);

  tool_bar->SetActiveTool(brush);
}
