#include <stdlib.h>

int maxAdjacentDistance(int* nums, int numsSize) {
  int max = abs(nums[0] - nums[numsSize - 1]);
  for (int i = 1; i < numsSize; ++i) {
    const int diff = abs(nums[i - 1] - nums[i]);
    if (diff > max) max = diff;
  }
  return max;
}
