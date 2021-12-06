#include "gui_window.hpp"


gui::Window::Window(const glib::IntRect& location):
             AbstractContainerWidget(location) {}


gui::EventResult gui::Window::OnMouseButtonPressed(glib::Vector2i local_mouse_position,
                                                   glib::Vector2i global_mouse_position,
                                                   MouseButton button) {
  glib::Vector2i mouse_position_inside = local_mouse_position - m_location.m_position;
  for (auto child_it =  m_children.begin();
            child_it != m_children.end();
            ++child_it) {
    auto child_ptr = *child_it;
    assert(child_ptr != nullptr);
    if (child_ptr->IsPointInside(mouse_position_inside)) {
      return child_ptr->OnMouseButtonPressed(mouse_position_inside,
                                             global_mouse_position,
                                             button);
    }
  }
  return EventResult::PROCESSED;
}


gui::EventResult gui::Window::OnMouseButtonReleased(glib::Vector2i local_mouse_position,
                                                    glib::Vector2i global_mouse_position,
                                                    MouseButton button) {
  glib::Vector2i mouse_position_inside = local_mouse_position - m_location.m_position;
  for (auto child_it =  m_children.begin();
            child_it != m_children.end();
            ++child_it) {
    auto child_ptr = *child_it;
    assert(child_ptr != nullptr);
    if (child_ptr->IsPointInside(mouse_position_inside)) {
      return child_ptr->OnMouseButtonReleased(mouse_position_inside,
                                              global_mouse_position,
                                              button);
    }
  }
  return EventResult::PROCESSED;
}


gui::EventResult gui::Window::OnMouseMove(glib::Vector2i new_local_mouse_position,
                                          glib::Vector2i new_global_mouse_position) {
  glib::Vector2i new_mouse_position_inside = new_local_mouse_position -
                                             m_location.m_position;
  for (auto child_it =  m_children.begin();
            child_it != m_children.end();
            ++child_it) {
    auto child_ptr = *child_it;
    assert(child_ptr != nullptr);
    child_ptr->OnMouseMove(new_mouse_position_inside, new_global_mouse_position);
  }
  return EventResult::PROCESSED;
}


void gui::Window::AddTitleBar(TitleBar* title_bar) {
  assert(title_bar != nullptr);

  m_title_bar = title_bar;
  AddChild(title_bar);
}


void gui::Window::AddContent(AbstractWidget* content_widget) {
  assert(content_widget != nullptr);

  m_content_widget = content_widget;
  AddChild(content_widget);
}


void gui::Window::Draw(glib::RenderTarget* render_target,
                       const glib::Vector2i& position) {
  assert(render_target != nullptr);

  glib::Vector2i position_inside = position + m_location.m_position;

  for (auto child_it =  m_children.begin();
            child_it != m_children.end();
            ++child_it) {
    auto child_ptr = *child_it;
    assert(child_ptr != nullptr);

    child_ptr->Draw(render_target, position_inside);
  }
}
