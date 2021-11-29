#include "gui_abstract_view_functor.hpp"


gui::AbstractViewFunctor::~AbstractViewFunctor() = default;


gui::CloseViewFunctor::CloseViewFunctor(AbstractView* view): m_view(view) {
  assert(m_view != nullptr);
}


void gui::CloseViewFunctor::operator()() {
  m_view->OnClose();
}
