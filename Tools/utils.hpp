#ifndef UTILS_HPP
#define UTILS_HPP

#include <cstddef>
#include <cstdio>


namespace tls {
  size_t RoundUpDiv(const size_t divident, const size_t divider);


  template<typename T>
  T Min(const T& first, const T& second) {
    return first < second ? first : second;
  }


  template<typename T>
  T Max(const T& first, const T& second) {
    return first > second ? first : second;
  }
}


#endif /* utils.hpp */