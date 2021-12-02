/**
 * \file Header file with describing of abstract view
*/
#ifndef GUI_ABSTRACT_VIEW_HPP
#define GUI_ABSTRACT_VIEW_HPP


#include "glib.hpp"
#include "gui_abstract_view_skin.hpp"
#include <list>


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


  class AbstractView {
   protected:
    friend class TitleBar;
    friend class Window;

    glib::IntRect m_location;

    AbstractView*     m_child_under_mouse_hovered = nullptr;
    AbstractView*     m_child_under_mouse_pressed = nullptr;
    glib::Vector2i    m_curr_mouse_position;

    bool m_should_close    = false;
    bool m_needs_to_render = true;
   public:
    AbstractView() = default;
    virtual ~AbstractView() = 0;


    void SetLocation(const glib::IntRect& location);

    glib::IntRect Location() const;

    bool IsPointInside(glib::Vector2i point) const;

    virtual EventResult OnMouseButtonPressed(glib::Vector2i mouse_position, MouseButton button);

    virtual EventResult OnMouseButtonReleased(glib::Vector2i mouse_position, MouseButton button);

    virtual EventResult OnMouseHoverBegin(glib::Vector2i mouse_position);

    virtual EventResult OnMouseHoverEnd(glib::Vector2i mouse_position);

    virtual EventResult OnMouseMove(glib::Vector2i new_mouse_position);

    virtual EventResult OnUnknownEvent();

    EventResult OnClose();

    void MatchForClose();

    void Move(const glib::Vector2i& delta_position);

    virtual void Draw(glib::RenderTarget* render_target,
                      const glib::Vector2i& position) = 0;
  };
}


#endif /* gui_abstract_view.hpp */
