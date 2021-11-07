#ifndef GUI_BUTTON_HPP
#define GUI_BUTTON_HPP


#include "glib.hpp"
#include "gui_view.hpp"


namespace gui {
  enum class ButtonPressState {
    PRESSED,
    RELEASED
  };


  class Button: public View {
   protected:
    ButtonPressState m_press_state = ButtonPressState::RELEASED;
    ButtonDelegate*  m_button_delegate = nullptr;
   public:
    Button() = default;
    Button(const glib::FloatRect& location);
    ~Button() = default;

    void SetPressState(const ButtonPressState press_state);
    ButtonPressState PressState() const;
  };


  class RectButton: public Button {
   public:
    RectButton() = default;
    RectButton(const glib::FloatRect& location);
    ~RectButton() = default;

    bool IsMouseInside(const glib::Vector2f& mouse_position) override;

    void OnLeftMouseButtonPressed() override;
  };
}


#endif /* gui_button.hpp */
