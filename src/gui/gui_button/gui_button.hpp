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
  class Button: public AbstractView {
   protected:
    glib::Vector2i m_curr_mouse_position;

    AbstractViewFunctor* m_functor = nullptr;
    AbstractButtonSkin*     m_skin = nullptr;
   public:
    Button() = default;
    Button(AbstractViewFunctor* functor, AbstractButtonSkin* skin);
    ~Button() override = default;

    void SetSkin(AbstractButtonSkin* skin);
    void SetFunctor(AbstractViewFunctor* functor);

    void Draw(glib::RenderTarget* render_target, const glib::Vector2i& position) override;
  };
}


#endif /* gui_button.hpp */
