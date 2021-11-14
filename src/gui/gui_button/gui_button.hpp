/**
 * \file
*/
#ifndef GUI_BUTTON_HPP
#define GUI_BUTTON_HPP


#include "glib.hpp"
#include "gui_abstract_view.hpp"
#include "gui_abstract_view_functor.hpp"
#include "gui_button_skin.hpp"


namespace gui {
  /**
   * Button press state
  */
  enum class ButtonPressState {
    IDLE, ///< When button is idle
    HOVERED, ///< When button is hovered
    PRESSED ///< When button is pressed
  };


  class Button: public AbstractView {
   protected:
    ButtonPressState m_press_state = ButtonPressState::IDLE; ///< Button press state

    AbstractFunctor* m_functor = nullptr;
    AbstractButtonSkin* m_skin = nullptr;
   public:
    Button() = default;
    Button(AbstractFunctor* functor, AbstractButtonSkin* skin);
    ~Button() override = 0;

    void SetSkin(AbstractButtonSkin* skin);
    void SetFunctor(AbstractFunctor* functor);

    EventResult OnLeftMouseButtonPressed(const glib::Vector2u& mouse_position) override;
    EventResult OnLeftMouseButtonReleased(const glib::Vector2u& mouse_position) override;

    void Draw(glib::RenderTarget* render_target, const glib::Vector2u& position) override;
  };
}


#endif /* gui_button.hpp */
