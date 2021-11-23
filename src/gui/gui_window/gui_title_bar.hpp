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
    glib::Vector2i DELTA_BUTTON = glib::Vector2i(-5, 0);

    TitleBarSkin* m_skin      = nullptr;
    Button* m_minimize_button = nullptr;
    Button* m_maximize_button = nullptr;
    Button* m_close_button    = nullptr;
    Title* m_title            = nullptr;

    MoveFunctor m_move_functor;
   public:
    TitleBar() = default;
    TitleBar(TitleBarSkin* skin);
    TitleBar(TitleBarSkin* skin, Button* minimize_button,
             Button* maximize_button, Button* close_button, Title* title,
             const MoveFunctor& move_functor);
    ~TitleBar() = default;

    void Draw(glib::RenderTarget* render_target,
              const glib::Vector2i& position) override;

    void OnLeftMouseDrag(glib::Vector2i new_mouse_position) override;

    void OnLeftMouseButtonPressed(glib::Vector2i mouse_position) override;
    void OnLeftMouseButtonReleased(glib::Vector2i mouse_position) override;

    void AddSkin(TitleBarSkin* skin);

    void AddMinimizeButton(Button* minimize_button);
    void AddMaximizeButton(Button* maximize_button);
    void AddCloseButton(Button* close_button);
    void AddTitle(Title* title);

    void AddMoveFunctor(const MoveFunctor& move_functor);
  };
}


#endif /* gui_title_bar.hpp */
