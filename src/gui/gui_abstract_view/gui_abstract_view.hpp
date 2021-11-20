/**
 * \file Header file with describing of abstract view
*/
#ifndef GUI_ABSTRACT_VIEW_HPP
#define GUI_ABSTRACT_VIEW_HPP


#include "glib.hpp"
#include "gui_abstract_view_skin.hpp"
#include <list>


namespace gui {
  /**
   * Abstract view with common details
  */
  class AbstractView {
   protected:
    std::list<AbstractView*> m_children; ///< List of children views
    AbstractViewSkin* m_skin;

    AbstractView* m_child_under_mouse = nullptr;

    bool m_should_close = false; ///< If view needs to be closed
   public:
    /**
     * Default constructor
    */
    AbstractView() = default;
    /**
     * Constructor initialising location
    */
    AbstractView(AbstractViewSkin* skin);
    /**
     * Pure virtual default destructor
    */
    virtual ~AbstractView() = 0;

    /**
     * Sets location
    */
    void SetLocation(const glib::UIntRect& location);

    glib::UIntRect Location() const;

    /**
     * Checks if point inside the view
    */
    virtual bool IsPointInside(const glib::Vector2u& point);

    /**
     * Handler of left mouse button pressed event
     * \param mouse_position Mouse position
    */
    virtual void OnLeftMouseButtonPressed(const glib::Vector2u& mouse_position);

    virtual void OnMouseHoverBegin(const glib::Vector2u& mouse_position);

    virtual void OnMouseHoverEnd(const glib::Vector2u& mouse_position);

    /**
     * Handler of right mouse button pressed event
     * \param mouse_position Mouse position
    */
    virtual void OnRightMouseButtonPressed(const glib::Vector2u& mouse_position);

    /**
     * Handler of left mouse button released event
     * \param mouse_position Mouse position
    */
    virtual void OnLeftMouseButtonReleased(const glib::Vector2u& mouse_position);
    /**
     * Handler of right mouse button released event
     * \param mouse_position Mouse position
    */
    virtual void OnRightMouseButtonReleased(const glib::Vector2u& mouse_position);

    virtual void OnMouseMove(const glib::Vector2u& new_mouse_position);

    /**
     * Handler of close event
    */
    void OnClose();

    /**
     * Matches view for close
    */
    void MatchForClose();


    virtual void Draw(glib::RenderTarget* render_target,
                      const glib::Vector2u& position);
  };
}


#endif /* gui_abstract_view.hpp */
