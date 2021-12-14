#ifndef GUI_BRUSH_HPP
#define GUI_BRUSH_HPP


#include "glib_color.hpp"
#include "gui_abstract_tool.hpp"
#include "gui_canvas.hpp"


namespace gui {
  class Brush: public AbstractTool {
   protected:
    glib::ColorRGBA m_color;
    int m_thickness = 3;
   public:
    Brush() = default;
    Brush(const glib::ColorRGBA& color, int thickness);
    ~Brush() = default;

    static Brush* GetInstance();

    void Apply(Canvas* canvas) override;
  };
}


#endif /* gui_brush.hpp */
