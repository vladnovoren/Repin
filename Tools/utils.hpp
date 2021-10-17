#ifndef UTILS_HPP
#define UTILS_HPP

#include <cstddef>
#include <cstdio>


namespace ts {
  size_t RoundUpDiv(const size_t divident, const size_t divider);


  template<typename T>
  T min(const T& first, const T& second) {
    return first < second ? first : second;
  }


  template<typename T>
  T max(const T& first, const T& second) {
    return first > second ? first : second;
  }
}


#endif /* utils.hpp */