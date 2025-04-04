#include <cstdint>

extern "C" {
uint32_t reverseBits(uint32_t n);
}

std::uint32_t solution_c(std::uint32_t n) {
  return reverseBits(n);
}
