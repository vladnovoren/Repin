#ifndef GLIB_FONT_HPP
#define GLIB_FONT_HPP


#include "SFML/Graphics.hpp"
#include <cassert>


namespace glib {
  class Font {
   protected:
    sf::Font m_sf_font;
   public:
    Font() = default;
    Font(const sf::Font& sf_font);

    bool LoadFromFile(const char* file_path);
    
    const sf::Font& GetSFMLFont() const;
  };
}


#endif /* glib_font.hpp */
