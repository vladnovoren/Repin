#ifndef GLIB_TEXT_HPP
#define GLIB_TEXT_HPP


#include "glib_color.hpp"
#include "glib_tools.hpp"
#include "glib_font.hpp"


namespace glib {
  class Text {
   protected:
    sf::Text m_sf_text;
   public:
    Text() = default;
    Text(const char* label, const Font& font);
    ~Text() = default;

    void SetLabel(const char* label);
    void SetFontSize(unsigned int size);
    void SetColor(const ColorRGBA& color);
    void SetPosition(const Vector2i& position);
    void SetCenterPosition(const Vector2i& center_position);

    Vector2i GetSize() const;

    void Move(const Vector2i& delta);
  };
}


#endif /* glib_text.hpp */
