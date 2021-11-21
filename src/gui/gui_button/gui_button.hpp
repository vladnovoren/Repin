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
    AbstractButtonSkin* m_skin = nullptr;
   public:
    Button() = default;
    Button(AbstractViewFunctor* functor, AbstractButtonSkin* skin);
    ~Button() override = 0;

    void SetSkin(AbstractButtonSkin* skin);
    void SetFunctor(AbstractViewFunctor* functor);

    void OnMouseHoverBegin(glib::Vector2i mouse_position) override;
    void OnMouseHoverEnd(glib::Vector2i mouse_position) override;

    void OnMouseMove(glib::Vector2i new_mouse_position) override;
    void OnLeftMouseButtonPressed(glib::Vector2i mouse_position) override;
    void OnLeftMouseButtonReleased(glib::Vector2i mouse_position) override;

    void Draw(glib::RenderTarget* render_target, const glib::Vector2i& position) override;
  };
}


#endif /* gui_button.hpp */
