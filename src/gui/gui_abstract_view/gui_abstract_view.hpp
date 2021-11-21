/**
 * \file Header file with describing of abstract view
*/
#ifndef GUI_ABSTRACT_VIEW_HPP
#define GUI_ABSTRACT_VIEW_HPP


#include "glib.hpp"
#include "gui_default_view_skin.hpp"
#include <list>


namespace gui {
  enum class MousePressState {
    IDLE,
    HOVERED,
    PRESSED
  };

  /**
   * Abstract view with common details
  */
  class AbstractView {
   protected:
    std::list<AbstractView*> m_children; ///< List of children views
    DefaultViewSkin* m_skin = nullptr;

    AbstractView* m_child_under_mouse = nullptr;
    MousePressState m_mouse_press_state = MousePressState::IDLE;

    bool m_should_close = false; ///< If view needs to be closed
   public:
    /**
     * Default constructor
    */
    AbstractView() = default;
    /**
     * Constructor initialising location
    */
    AbstractView(DefaultViewSkin* skin);
    /**
     * Pure virtual default destructor
    */
    virtual ~AbstractView() = 0;

    /**
     * Sets location
    */
    void SetLocation(const glib::IntRect& location);

    glib::IntRect Location() const;

    /**
     * Checks if point inside the view
    */
    virtual bool IsPointInside(const glib::Vector2i& point);

    /**
     * Handler of left mouse button pressed event
     * \param mouse_position Mouse position
    */
    virtual void OnLeftMouseButtonPressed(glib::Vector2i mouse_position);

    virtual void OnMouseHoverBegin(glib::Vector2i mouse_position);

    virtual void OnMouseHoverEnd(glib::Vector2i mouse_position);

    /**
     * Handler of right mouse button pressed event
     * \param mouse_position Mouse position
    */
    virtual void OnRightMouseButtonPressed(glib::Vector2i mouse_position);

    /**
     * Handler of left mouse button released event
     * \param mouse_position Mouse position
    */
    virtual void OnLeftMouseButtonReleased(glib::Vector2i mouse_position);
    /**
     * Handler of right mouse button released event
     * \param mouse_position Mouse position
    */
    virtual void OnRightMouseButtonReleased(glib::Vector2i mouse_position);

    virtual void OnMouseMove(glib::Vector2i new_mouse_position);

    /**
     * Handler of close event
    */
    void OnClose();

    /**
     * Matches view for close
    */
    void MatchForClose();


    void Move(const glib::Vector2i& delta_position);


    virtual void Draw(glib::RenderTarget* render_target,
                      const glib::Vector2i& position);

    void MoveChildUp(std::list<AbstractView*>::iterator child_it);
  };
}


#endif /* gui_abstract_view.hpp */
