#include "gui_abstract_container_view.hpp"


void gui::AbstractContainerView::DeleteMatched() {
  auto child_it = m_children.begin();
  while (child_it != m_children.end()) {
    auto child_ptr = *child_it;
    assert(child_ptr != nullptr);
    if (child_ptr->ShouldClose()) {
      delete child_ptr;
      m_children.erase(child_it++);
    } else {
      child_ptr->DeleteMatched();
      ++child_it;
    }
  }
}
