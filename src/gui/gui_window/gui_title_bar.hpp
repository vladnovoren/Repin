#ifndef GUI_TITLE_BAR_HPP
#define GUI_TITLE_BAR_HPP


#include "gui_abstract_view.hpp"
#include "gui_button.hpp"
#include "gui_title.hpp"
#include "gui_title_bar_skin.hpp"
#include "gui_move_functor.hpp"


namespace gui {
  class TitleBar: public AbstractView {
   protected:
    static constexpr glib::Vector2f DELTA_BUTTON = glib::Vector2f(0, -5);

    TitleBarSkin* m_skin      = nullptr;
    Button* m_minimize_button = nullptr;
    Button* m_maximize_button = nullptr;
    Button* m_close_button    = nullptr;
    Title* m_title            = nullptr;

    glib::Vector2i m_curr_mouse_position;
    MoveFunctor m_move_functor;

   public:
    TitleBar() = default;
    TitleBar(TitleBarSkin* skin, Button* minimize_button,
             Button* maximize_button, Button* close_button, Title* title, const MoveFunctor& move_functor);
    ~TitleBar() = default;

    void Draw(glib::RenderTarget* render_target,
              const glib::Vector2i& position) override;

    void OnMouseMove(glib::Vector2i new_mouse_position) override;
    void OnLeftMouseButtonPressed(glib::Vector2i mouse_position) override;
    void OnLeftMouseButtonReleased(glib::Vector2i mouse_position) override;
  };
}


#endif /* gui_title_bar.hpp */
