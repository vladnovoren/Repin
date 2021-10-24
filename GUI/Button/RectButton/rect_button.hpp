#ifndef RECT_BUTTON_HPP
#define RECT_BUTTON_HPP


#include "button.hpp"


namespace GUI {
  class RectButton: public Button {
    protected:
      void OnMouseEnter(const tls::Vector2f& local_mouse_position) override;
      void OnMouseExit(const tls::Vector2f& local_mouse_position) override;
      void OnMouseHitted(const tls::Vector2f& local_mouse_position) override;
      void OnMouseReleased(const tls::Vector2f& local_mouse_position) override;
    public:
      RectButton();
      RectButton(const glib::IntRect& location);
  };
}




#endif /* rect_button.hpp */