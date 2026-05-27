#include <stdlib.h>

int* maxValue(int* nums, int numsSize, int* returnSize) {
  int* maxs = malloc(numsSize * sizeof(int));
  int* mins = malloc(numsSize * sizeof(int));

  maxs[0] = nums[0];
  for (int i = 1; i < numsSize; ++i) {
    maxs[i] = maxs[i - 1] >= nums[i] ? maxs[i - 1] : nums[i];
  }

  mins[numsSize - 1] = nums[numsSize - 1];
  nums[numsSize - 1] = maxs[numsSize - 1];

  for (int i = numsSize - 1; i > 0; --i) {
    mins[i - 1] = mins[i] <= nums[i - 1] ? mins[i] : nums[i - 1];
    nums[i - 1] = maxs[i - 1] > mins[i] ? nums[i] : maxs[i - 1];
  }

  free(maxs);
  free(mins);

  *returnSize = numsSize;
  return nums;
}
