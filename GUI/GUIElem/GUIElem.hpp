#ifndef GUI_ELEM_HPP
#define GUI_ELEM_HPP


#include <list>
#include "GLib/glib.hpp"


namespace GUI {
  class GUIElem {
  public:
    enum class PressState {
      ENTERED,
      EXITED,
      PRESSED,
      RELEASED
    };
  protected:
    glib::IntRect location;
    GUI::GUIElem* parent;
    std::list<GUIElem*> children;

    PressState press_state;

    virtual void OnMouseEnter(const tls::Vector2f& local_mouse_position) = 0;
    virtual void OnMouseExit(const tls::Vector2f& local_mouse_position) = 0;
    virtual void OnMouseHitted(const tls::Vector2f& local_mouse_position) = 0;
    virtual void OnMouseReleased(const tls::Vector2f& local_mouse_position) = 0;
  public:
    GUIElem();
    GUIElem(const glib::IntRect& location);
    virtual ~GUIElem() = 0;

    void AddChild(GUIElem* child);

    void SetLocation(const glib::IntRect& location);
    void Move(const tls::Vector2i& delta);

    virtual void Render() = 0;
    virtual void CopyToRenderWindow(glib::RenderWindow* render_window) = 0;
    virtual void Tick(const double dt) = 0;
  };


  // class ButtonViewDelegate;


  // class ButtonView: public View {
  // public:
  //   enum class State {
  //     PRESSED,
  //     FOCUSED,
  //     RELEASED
  //   };
  // protected:
  //   ButtonViewDelegate* delegate;
  // public:
  //   ButtonView(const Rect& rect, const ColorRGB& color, const Type type,
  //             ButtonViewDelegate* delegate);

  //   ~ButtonView();

  //   void Tick(const double dt) override;

  //   bool IsMouseHitted(const Vector2f& mouse_pos) override;

  //   void OnMouse(const Vector2f& mouse_pos) override;

  //   void Render(Graphics* graphics) override;
  // };


  // class ButtonAddBallView: public ButtonView {
  // };


  // class ButtonViewDelegate {
  // public:
  //   virtual void OnClick(const ButtonView::Type type) = 0;
  // };


  // class WindowView: public View, public ButtonViewDelegate {
  // protected:
  // public:
  //   WindowView(const Rect& rect, const ColorRGB& color);

  //   ~WindowView();

  //   void Tick(const double dt) override;

  //   bool IsMouseHitted(const Vector2f& mouse_pos) override;

  //   void OnClick(const ButtonView::Type type);

  //   void OnMouse(const Vector2f& mouse_pos) override;

  //   void Render(Graphics* graphics) override;
  // };
}


#endif /* GUIElem.hpp */
