#ifndef BUTTON_HPP
#define BUTTON_HPP

#include "GUIElem.hpp"


namespace GUI {
  class Button: public GUIElem {
  public:
    Button();
    Button(const IntRect& location);
    virtual ~Button() = 0;
  protected:
    PressState press_state = ;
  };
}


#endif /* button.hpp */
