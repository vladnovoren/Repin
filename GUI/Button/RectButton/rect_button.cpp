#include "rect_button.hpp"


GUI::RectButton::RectButton() {}


GUI::RectButton::RectButton(const glib::IntRect& location):
                 GUIElem(location) {}


void GUI::RectButton::OnMouseEnter(const tls::Vector2f& local_mouse_position) {
  press_state = PressState::ENTERED;
}


void GUI::RectButton::OnMouseExit(const tls::Vector2f& local_mouse_position) {
  press_state = PressState::EXITED;
}


void GUI::RectButton::OnMouseHitted(const tls::Vector2f& local_mouse_position) {
  press_state = PressState::PRESSED;
  if ()
}


void GUI::RectButton::OnMouseReleased(const tls::Vector2f& local_mouse_position) {

}