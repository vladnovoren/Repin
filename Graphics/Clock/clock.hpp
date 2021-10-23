#ifndef CLOCK_HPP
#define CLOCK_HPP

#include "SFML/Graphics.hpp"


namespace glib {
  class Clock {
    sf::Clock sf_clock;
  private:
    double GetElapsedTime();
    double Restart();
  };
}


#endif /* clock.hpp */