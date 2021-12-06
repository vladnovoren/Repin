#ifndef GUI_ABSTRACT_WIDGET_HPP
#define GUI_ABSTRACT_WIDGET_HPP


#include "glib.hpp"
#include "gui_abstract_widget_skin.hpp"


namespace gui {
  enum class EventResult {
    NO_EVENT,
    PROCESSED,
    NOT_PROCESSED
  };


  enum class MouseButton {
    NO_BUTTON,
    LEFT,
    MIDDLE,
    RIGHT
  };


  class AbstractWidget {
   protected:
    friend class TitleBar;
    friend class Window;

    glib::IntRect m_location;

    AbstractWidget* m_parent_widget = nullptr;

    bool m_should_close    = false;
    bool m_needs_to_render = true;
   public:
    AbstractWidget() = default;
    AbstractWidget(const glib::IntRect& location);
    virtual ~AbstractWidget() = 0;


    void SetLocation(const glib::IntRect& location);

    glib::IntRect Location() const;

    virtual bool IsPointInside(glib::Vector2i point) const;

    glib::Vector2i PointRelativeToParent(glib::Vector2i point) const;

    virtual EventResult OnMouseButtonPressed(glib::Vector2i local_mouse_position,
                                             glib::Vector2i global_mouse_position,
                                             MouseButton button);

    virtual EventResult OnMouseButtonReleased(glib::Vector2i local_mouse_position,
                                              glib::Vector2i global_mouse_position,
                                              MouseButton button);

    virtual EventResult OnMouseHoverBegin(glib::Vector2i mouse_position);

    virtual EventResult OnMouseHoverEnd(glib::Vector2i mouse_position);

    virtual EventResult OnMouseMove(glib::Vector2i new_local_mouse_position,
                                    glib::Vector2i new_global_mouse_position);

    virtual EventResult OnUnknownEvent();

    EventResult OnClose();

    void MatchForClose();

    bool ShouldClose() const;

    virtual void DeleteMatched();

    void Move(const glib::Vector2i& delta_position);

    virtual void Draw(glib::RenderTarget* render_target,
                      const glib::Vector2i& position) = 0;
  };
}


#endif /* gui_abstract_widget.hpp */
