#include "gui_button.hpp"


gui::RectButton::RectButton(const glib::FloatRect& location):
                 m_location(location) {}


bool gui::RectButton::IsMouseInside(const glib::Vector2f& mouse_position) {
  return m_location.IsPointInRect(position);
}


void gui::Button::OnLeftMouseButtonPressed() {
  m_press_state = ButtonPressState::PRESSED;
  m_button_delegate->
}


void gui::Button::OnLeftMouseButtonReleased() {
  m_press_state = ButtonPressState::RELEASED;
}
