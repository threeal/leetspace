#include <limits.h>

int minimumPairRemoval(int* nums, int numsSize) {
  const int prevSize = numsSize;
  while (numsSize > 1) {
    int minSum = INT_MAX, i = 1, minI = 0;
    while (i < numsSize && nums[i] >= nums[i - 1]) {
      if (nums[i] + nums[i - 1] < minSum) {
        minSum = nums[i] + nums[i - 1];
        minI = i;
      }
      ++i;
    }

    if (i == numsSize) break;

    while (i < numsSize) {
      if (nums[i] + nums[i - 1] < minSum) {
        minSum = nums[i] + nums[i - 1];
        minI = i;
      }
      ++i;
    }

    nums[minI - 1] = minSum;
    for (int i = minI + 1; i < numsSize; ++i) {
      nums[i - 1] = nums[i];
    }
    --numsSize;
  }

  return prevSize - numsSize;
}
