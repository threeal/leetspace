#include <stdbool.h>

bool canSortArray(int* nums, int numsSize) {
  int prevMax = 0, max = 0, bitCount = -1;
  for (int i = 0; i < numsSize; ++i) {
    const int count = __builtin_popcount(nums[i]);
    if (count == bitCount) {
      if (nums[i] < prevMax) return false;
      if (nums[i] > max) max = nums[i];
    } else {
      if (nums[i] < max) return false;
      bitCount = count;
      prevMax = max;
      max = nums[i];
    }
  }

  return true;
}
