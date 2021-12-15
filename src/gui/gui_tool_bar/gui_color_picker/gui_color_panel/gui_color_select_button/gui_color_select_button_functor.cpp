#include "gui_color_select_button_functor.hpp"
#include "gui_color_select_button.hpp"


gui::ColorSelectButtonFunctor::ColorSelectButtonFunctor(ColorSelectButton* owner,
                                                        const glib::ColorRGBA& color):
                               ColorSelectFunctor(color), m_owner(owner) {
  assert(owner != nullptr);
}


void gui::ColorSelectButtonFunctor::operator()() {
  assert(m_owner != nullptr);

  ColorPanel* color_panel = ColorPanel::GetInstance();
  auto found = std::find(color_panel->m_children.begin(),
                         color_panel->m_children.end(),
                         m_owner);
  if (found == color_panel->m_children.end()) {
    PRINT_LINE_LOCATION
    printf("bad ColorSelectButton\n");
    return;
  }
  for (auto it =  color_panel->m_children.begin();
            it != color_panel->m_children.end();
            ++it) {
    auto child_ptr = *it;
    assert(child_ptr != nullptr);
    if (child_ptr != m_owner) {
      auto casted_child_ptr = dynamic_cast<ColorSelectButton*>(child_ptr);
      casted_child_ptr->
    }
  }
}


void gui::ColorSelectButtonFunctor::operator()(ColorSelectButton* owner,
                                               const glib::ColorRGBA& color) {
  assert(owner != nullptr);

  m_owner = owner;
  m_color = color;
  operator()();
}
