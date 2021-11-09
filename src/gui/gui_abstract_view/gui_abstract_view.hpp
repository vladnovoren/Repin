/**
 * \file Header file with describing of abstract view
*/
#ifndef GUI_ABSTRACT_VIEW_HPP
#define GUI_ABSTRACT_VIEW_HPP


#include "glib.hpp"
#include <list>


namespace gui {
  enum class EventResult {
    PROCESSED_ALL,
    PROCESSED_NOT_ALL,
    REJECTED
  };

  /**
   * Abstract view with common details
  */
  class AbstractView {
   protected:
    glib::FloatRect m_location; ///< Relative location to parent view
    std::list<AbstractView*> m_children; ///< List of children views

    bool m_should_close = false; ///< If view needs to be closed
   public:
    /**
     * Default constructor
    */
    AbstractView() = default;
    /**
     * Constructor initialising location
    */
    AbstractView(const glib::FloatRect& location);
    /**
     * Pure virtual default destructor
    */
    virtual ~AbstractView() = 0;

    /**
     * Sets location
    */
    void SetLocation(const glib::FloatRect& location);
    glib::FloatRect Location() const;

    /**
     * Checks if point inside the view
    */
    virtual bool IsPointInside(const glib::Vector2f& point);

    /**
     * Handler of left mouse button pressed event
     * \param mouse_position Mouse position
    */
    virtual EventResult OnLeftMouseButtonPressed(const glib::Vector2f& mouse_position);
    /**
     * Handler of right mouse button pressed event
     * \param mouse_position Mouse position
    */
    virtual EventResult OnRightMouseButtonPressed(const glib::Vector2f& mouse_position);

    /**
     * Handler of left mouse button released event
     * \param mouse_position Mouse position
    */
    virtual EventResult OnLeftMouseButtonReleased(const glib::Vector2f& mouse_position);
    /**
     * Handler of right mouse button released event
     * \param mouse_position Mouse position
    */
    virtual EventResult OnRightMouseButtonReleased(const glib::Vector2f& mouse_position);

    /**
     * Handler of close event
    */
    EventResult OnClose();

    /**
     * Matches view for close
    */
    void MatchForClose();
  };
}


#endif /* gui_abstract_view.hpp */
