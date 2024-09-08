#include <stdbool.h>
#include <stdint.h>

bool isCovered(
    int** ranges, int rangesSize, int* rangesColSize, int left, int right) {
  (void)rangesColSize;
  uint64_t actual = 0;
  for (int i = rangesSize - 1; i >= 0; --i) {
    actual |= ((1ul << (ranges[i][1] + 1)) - 1) & ~((1ul << ranges[i][0]) - 1);
  }
  uint64_t expected = ((1ul << (right + 1)) - 1) & ~((1ul << left) - 1);
  return (actual & expected) == expected;
}
