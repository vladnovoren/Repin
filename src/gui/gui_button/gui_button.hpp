/**
 * \file
*/
#ifndef GUI_BUTTON_HPP
#define GUI_BUTTON_HPP


#include "glib.hpp"
#include "gui_abstract_view.hpp"


namespace gui {
  /**
   * Button press state
  */
  enum class ButtonPressState {
    IDLE, ///< When button is idle
    HOVERED, ///< When button is hovered
    PRESSED ///< When button is pressed
  };


  /**
   * Abstract button with common details.
  */
  class AbstractButton: public AbstractView {
   protected:
    ButtonPressState m_press_state = ButtonPressState::IDLE; ///< Button press state
    glib::Texture*   m_curr_texture = nullptr; ///< Pointer to current texture
    glib::Texture*   m_idle_texture = nullptr; ///< Texture of idle state
    glib::Texture*   m_hovered_texture = nullptr; ///< Texture of hovered state
    glib::Texture*   m_pressed_texture = nullptr; ///< Texture of pressed state
   public:
    /**
     * Default constructor
    */
    AbstractButton() = default;
    /**
     * Constructor initialising main members
     * \param location        Relative location to parent view
     * \param idle_texture    Texture of idle state
     * \param hovered_texture Texture of hovered state
     * \param pressed_texture Texture of pressed state
    */
    AbstractButton(const glib::FloatRect& location, glib::Texture* idle_texture,
                   glib::Texture* hovered_texture,
                   glib::Texture* pressed_texture);
    /**
     * Pure virtual default destructor
    */
    ~AbstractButton() override = 0;

    /**
     * Sets textures
     * \param idle_texture    Texture of idle state
     * \param hovered_texture Texture of hovered state
     * \param pressed_texture Texture of pressed state
    */
    void SetSkin(glib::Texture* idle_texture, glib::Texture* hovered_texture,
                 glib::Texture* pressed_texture);
  };


  /**
   * Rectangle-shaped button
  */
  class RectButton: public AbstractButton {
   public:
    /**
     * Default constructor
    */
    RectButton() = default;
    /**
     * Constructor initialising main members
     * \param location        Relative location to parent view
     * \param idle_texture    Texture of idle state
     * \param hovered_texture Texture of hovered state
     * \param pressed_texture Texture of pressed state
    */
    RectButton(const glib::FloatRect& location, glib::Texture* idle_texture,
               glib::Texture* hovered_texture, glib::Texture* pressed_texture);
    /**
     * Default constructor
    */
    ~RectButton() = default;

    /**
     * Handler of left mouse button pressed event
     * \param mouse_position Mouse position
    */
    EventResult OnLeftMouseButtonPressed(const glib::Vector2f& mouse_position) override;
  };


  /**
   * Circle-shaped button
  */
  class CircleButton: public AbstractButton {
   protected:
    glib::Circle m_circle; ///< Active circle zone
   public:
    /**
     * Default constructor
    */
    CircleButton() = default;
    /**
     * Constructor initialising main members
     * \param location        Relative location to parent view
     * \param circle          Active circle zone
     * \param idle_texture    Texture of idle state
     * \param hovered_texture Texture of hovered state
     * \param pressed_texture Texture of pressed state
    */
    CircleButton(const glib::FloatRect& location, const glib::Circle& circle,
                 glib::Texture* idle_texture, glib::Texture* hovered_texture,
                 glib::Texture* pressed_texture);
    /**
     * Default destructor
    */
    ~CircleButton() override = default;

    /**
     * Sets textures and button circle
     * \param circle          Button circle
     * \param idle_texture    Texture of idle state
     * \param hovered_texture Texture of hovered state
     * \param pressed_texture Texture of pressed state
    */
    void SetSkin(const glib::Circle& circle, glib::Texture* idle_texture,
                 glib::Texture* hovered_texture,
                 glib::Texture* pressed_texture);

    /**
     * Checks if point inside the button
     * \param point Point
    */
    bool IsPointInside(const glib::Vector2f& point) override;
  };
}


#endif /* gui_button.hpp */
