#include "gui_canvas.hpp"
#include "gui_widget_manager.hpp"


gui::Canvas::Canvas(const glib::IntRect& location) {
  SetLocation(location);
}


void gui::Canvas::SetLocation(const glib::IntRect& location) {
  m_location = location;
  m_render_texture.Resize(location.m_size);
  m_render_texture.Clear(glib::ColorRGBA(1, 1, 1));
}


gui::EventResult gui::Canvas::OnMouseButtonPressed(glib::Vector2i local_mouse_position,
                                                   glib::Vector2i,
                                                   MouseButton button) {
  glib::Vector2i mouse_position_inside = local_mouse_position - m_location.m_position;
  if (button == MouseButton::LEFT) {
    m_is_drawing = true;
    DrawPoint(mouse_position_inside);
    m_prev_draw_point = mouse_position_inside;
    WidgetManager::GetInstance().AddMouseActiveWidget(this);
  }
  return EventResult::PROCESSED;
}


gui::EventResult gui::Canvas::OnMouseMove(glib::Vector2i new_local_mouse_position,
                                          glib::Vector2i) {
  EventResult result = EventResult::NOT_PROCESSED;
  glib::Vector2i mouse_position_inside = new_local_mouse_position - m_location.m_position;
  if (m_is_drawing) {
    DrawLine(glib::IntLine(m_prev_draw_point, mouse_position_inside));
    if (!IsPointInside(new_local_mouse_position)) {
      m_is_drawing = false;
      WidgetManager::GetInstance().RemoveMouseActiveWidget(this);
      result = EventResult::NOT_PROCESSED;
    } else {
      result = EventResult::PROCESSED;
    }
  }
  return result;
}


gui::EventResult gui::Canvas::OnMouseButtonReleased(glib::Vector2i,
                                                    glib::Vector2i,
                                                    MouseButton) {
  EventResult result = EventResult::NOT_PROCESSED;
  if (m_is_drawing) {
    WidgetManager::GetInstance().RemoveMouseActiveWidget(this);
    m_is_drawing = false;
    result = EventResult::PROCESSED;
  }
  return result;
}


void gui::Canvas::DrawPoint(glib::Vector2i point_position) {
  m_render_texture.RenderCircle(glib::IntCircle(point_position, m_thickness), m_color);
  m_render_texture.Display();
  m_needs_to_render = true;
}


void gui::Canvas::DrawLine(glib::IntLine line) {
  m_render_texture.RenderLine(line, m_thickness, m_color);
  DrawPoint(line.m_end);
  m_prev_draw_point = line.m_end;
  m_needs_to_render = true;
}


void gui::Canvas::Draw(glib::RenderTarget* render_target,
                       const glib::Vector2i& position) {
  assert(render_target != nullptr);

  glib::Vector2i position_inside = position + m_location.m_position;

  if (m_needs_to_render) {
    m_texture = m_render_texture.GetTexture();
    m_needs_to_render = false;
  }

  render_target->CopyTexture(m_texture, position_inside);
}
