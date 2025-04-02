#include <stdint.h>

uint32_t reverseBits(uint32_t n) {
  uint32_t out = 0;
  for (int i = 0; i < 32; ++i) {
    if ((n & (1l << i)) != 0) out |= 1l << (31 - i);
  }
  return out;
}
