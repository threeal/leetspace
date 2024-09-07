#include <stdint.h>

int makeTheIntegerZero(int num1, int num2) {
  int64_t target = num1;
  target -= num2;
  for (int n = 1; target >= n; ++n) {
    if (__builtin_popcountll(target) <= n) return n;
    target -= num2;
  }
  return -1;
}
