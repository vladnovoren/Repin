#ifndef GUI_CANVAS_HPP
#define GUI_CANVAS_HPP


#include "glib.hpp"
#include "gui_abstract_widget.hpp"


namespace gui {
  class Canvas: public AbstractWidget {
   protected:
    glib::Texture       m_texture;
    glib::RenderTexture m_render_texture;

    bool m_is_drawing = false;

    int m_thickness = 3;
    glib::ColorRGBA m_color;

    glib::Vector2i m_prev_draw_point = glib::Vector2i(-1, -1);
   public:
    Canvas() = default;
    Canvas(const glib::IntRect& location);
    ~Canvas() = default;

    void SetLocation(const glib::IntRect& location) override;

    EventResult OnMouseButtonPressed(glib::Vector2i local_mouse_position,
                                     glib::Vector2i global_mouse_position,
                                     MouseButton button) override;
    EventResult OnMouseButtonReleased(glib::Vector2i local_mouse_position,
                                      glib::Vector2i global_mouse_position,
                                      MouseButton button) override;
    EventResult OnMouseMove(glib::Vector2i new_local_mouse_position,
                            glib::Vector2i new_global_mouse_position) override;

    void DrawPoint(glib::Vector2i point_position);
    void DrawLine(glib::IntLine line);

    void Draw(glib::RenderTarget* render_target,
              const glib::Vector2i& position) override;
  };
}


#endif /* gui_canvas.hpp */
