#include <stdbool.h>

bool hasTrailingZeros(int* nums, int numsSize) {
  int evens = 0;
  for (int i = 0; i < numsSize; ++i) {
    if (nums[i] % 2 == 0) {
      if (++evens == 2) return true;
    }
  }
  return false;
}
