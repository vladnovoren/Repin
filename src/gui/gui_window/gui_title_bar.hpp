#ifndef GUI_TITLE_BAR_HPP
#define GUI_TITLE_BAR_HPP


#include "gui_abstract_view.hpp"
#include "gui_button.hpp"
#include "gui_title.hpp"
#include "gui_title_bar_skin.hpp"


namespace gui {
  class TitleBar: public AbstractView {
   protected:
    static const glib::Vector2f DELTA_BUTTON(0, -5);

    TitleBarSkin* m_skin      = nullptr;
    Button* m_minimize_button = nullptr;
    Button* m_maximize_button = nullptr;
    Button* m_close_button    = nullptr;
    Title* m_title            = nullptr;
    
   public:
    TitleBar() = default;
    TitleBar(TitleBarSkin* skin, Button* minimize_button,
             Button* maximize_button, Button* close_button,
             Title* title);
    ~TitleBar() = default;

    void Draw(glib::RenderTarget* render_target, const glib::Vector2f& position) override;
  };
}


#endif /* gui_title_bar.hpp */
