#include "gui_brush.hpp"


gui::Brush::Brush(const glib::ColorRGBA& color, int thickness):
            m_color(color), m_thickness(thickness) {}


void gui::Brush::Apply(Canvas* canvas) {
  assert(canvas != nullptr);

  glib::Vector2i prev_draw_point = canvas->GetPrevDrawPoint();
  glib::Vector2i curr_draw_point = canvas->GetCurrDrawPoint();

  if (prev_draw_point == curr_draw_point) {
    canvas->DrawPoint(curr_draw_point, m_color);
  } else {
    canvas->DrawLine(glib::IntLine(curr_draw_point, prev_draw_point, m_thickness),
                     m_color);
  }
}


void gui::Brush::Draw(glib::RenderTarget* render_target,
                      const glib::Vector2i&) {
  assert(render_target != nullptr);
}