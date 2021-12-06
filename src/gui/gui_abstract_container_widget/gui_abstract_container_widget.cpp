#include "gui_abstract_container_widget.hpp"


gui::AbstractContainerWidget::AbstractContainerWidget(const glib::IntRect& location):
                              AbstractWidget(location) {}


void gui::AbstractContainerWidget::DeleteMatched() {
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


gui::AbstractContainerWidget::~AbstractContainerWidget() {
  for (auto child_it =  m_children.begin();
            child_it != m_children.end();
            ++child_it) {
    auto child_ptr = *child_it;
    assert(child_ptr != nullptr);
    delete child_ptr;
  }
}


void gui::AbstractContainerWidget::ConnectChild(AbstractWidget* child) {
  assert(child != nullptr);

  child->m_parent_widget = this;
  m_children.push_front(child);
}
