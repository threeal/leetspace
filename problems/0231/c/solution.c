#include <stdbool.h>

bool isPowerOfTwo(int n) {
  if (n < 0) ++n;
  return __builtin_popcount(n) == 1;
}
