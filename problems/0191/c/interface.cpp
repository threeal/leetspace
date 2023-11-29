#include <cstdint>

extern "C" {
int hammingWeight(uint32_t n);
}

int solution_c(uint32_t n) {
  return hammingWeight(n);
}
