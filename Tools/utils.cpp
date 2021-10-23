#include "utils.hpp"


size_t tls::RoundUpDiv(const size_t divident, const size_t divider) {
  return (divident + divider - 1) / divider;
}
