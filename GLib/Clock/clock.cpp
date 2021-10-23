#include "clock.hpp"


double glib::Clock::GetElapsedTime() {
  return sf_clock.getElapsedTime().asSeconds();
}


double glib::Clock::Restart() {
  return sf_clock.restart().asSeconds();
}
