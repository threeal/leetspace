#include <stdint.h>

int arrangeCoins(int n) {
  uint_fast32_t low = 1;
  uint_fast32_t high = 92681;

  while (low < high) {
    const uint_fast32_t mid = (low + high + 1) / 2;
    if ((mid + mid * mid) / 2 > (uint_fast32_t)n) {
      high = mid - 1;
    } else {
      low = mid;
    }
  }
  return low;
}
