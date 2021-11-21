#ifndef GUI_MOVE_FUNCTOR_HPP
#define GUI_MOVE_FUNCTOR_HPP


#include "gui_abstract_view_functor.hpp"


namespace gui {
  class Window;

  class MoveFunctor: public AbstractViewFunctor {
   protected:
    Window* m_owner = nullptr;
    glib::Vector2i m_delta_position;
   public:
    MoveFunctor() = default;
    MoveFunctor(Window* owner);
    ~MoveFunctor() = default;

    void SetDeltaPosition(const glib::Vector2i& delta_position);

    void operator()() override;
    void operator()(const glib::Vector2i& delta_position);
  };
}


#endif /* gui_move_functor.hpp */
