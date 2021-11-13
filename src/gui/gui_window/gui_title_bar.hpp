#ifndef GUI_TITLE_BAR_HPP
#define GUI_TITLE_BAR_HPP


#include "gui_abstract_view.hpp"
#include "gui_button.hpp"
#include "gui_title.hpp"


namespace gui {
  class TitleBar: public AbstractView {
   protected:
    Button* m_close_button = nullptr;
    Title* m_title = nullptr;
   public:
    TitleBar() = default;
    TitleBar(Button* close_button, Title* title);
    ~TitleBar() = default;

    void Draw(glib::RenderTarget* render_target, const glib::Vector2f& position) override;
  };
}


#endif /* gui_title_bar.hpp */