#ifndef GUI_TITLE_BAR_HPP
#define GUI_TITLE_BAR_HPP


#include "gui_abstract_view.hpp"
#include "gui_button.hpp"
#include "gui_title.hpp"
#include "gui_title_bar_skin.hpp"


namespace gui {
  class TitleBar: public AbstractView {
   protected:
    TitleBarSkin* m_skin      = nullptr;
    Button* m_minimize_button = nullptr;
    Button* m_maximize_button = nullptr;
    Button* m_close_button    = nullptr;
    Title* m_title            = nullptr;

    glib::Vector2i m_old_mouse_position;

    bool m_is_dragging = false;
   public:
    TitleBar() = default;
    TitleBar(TitleBarSkin* skin);
    ~TitleBar() = default;

    void Draw(glib::RenderTarget* render_target,
              const glib::Vector2i& position) override;

    EventResult OnMouseButtonPressed(glib::Vector2i mouse_position, MouseButton button) override;
    EventResult OnMouseButtonReleased(glib::Vector2i mouse_position, MouseButton button) override;
    EventResult OnMouseMove(glib::Vector2i new_mouse_position) override;

    void AddSkin(TitleBarSkin* skin);

    // void AddMinimizeButton(Button* minimize_button);
    // void AddMaximizeButton(Button* maximize_button);
    // void AddCloseButton(Button* close_button);
    // void AddTitle(Title* title);
  };
}


#endif /* gui_title_bar.hpp */
