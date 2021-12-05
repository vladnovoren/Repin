#ifndef GUI_BUTTON_HPP
#define GUI_BUTTON_HPP


#include "glib.hpp"
#include "gui_abstract_widget.hpp"
#include "gui_abstract_widget_functor.hpp"
#include "gui_button_skin.hpp"


namespace gui {
  class Button: public AbstractWidget {
   protected:
    glib::Vector2i m_curr_mouse_position;

    AbstractWidgetFunctor* m_functor = nullptr;
    AbstractButtonSkin*     m_skin = nullptr;
   public:
    Button() = default;
    Button(const glib::IntRect& location,
           AbstractWidgetFunctor* functor,
           AbstractButtonSkin* skin);
    ~Button() override;

    bool IsPointInside(glib::Vector2i point) const override;

    void SetSkin(AbstractButtonSkin* skin);
    void SetFunctor(AbstractWidgetFunctor* functor);

    void Draw(glib::RenderTarget* render_target,
              const glib::Vector2i& position) override;

    EventResult OnMouseButtonPressed(glib::Vector2i mouse_position,
                                     MouseButton button) override;
    EventResult OnMouseMove(glib::Vector2i new_mouse_position) override;
    EventResult OnMouseButtonReleased(glib::Vector2i mouse_position,
                                      MouseButton button) override;
  };
}


#endif /* gui_button.hpp */
