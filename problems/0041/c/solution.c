#include <stdlib.h>

int firstMissingPositive(int* nums, int numsSize) {
  for (int i = 0; i < numsSize; ++i) {
    if (nums[i] <= 0) nums[i] = numsSize + 1;
  }

  for (int i = 0; i < numsSize; ++i) {
    const int j = abs(nums[i]);
    if (j <= numsSize && nums[j - 1] > 0) {
      nums[j - 1] *= -1;
    }
  }

  for (int i = 0; i < numsSize; ++i) {
    if (nums[i] > 0) return i + 1;
  }

  return numsSize + 1;
}
