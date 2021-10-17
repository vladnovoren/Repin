#include "utils.hpp"


size_t ts::RoundUpDiv(const size_t divident, const size_t divider) {
  return (divident + divider - 1) / divider;
}
