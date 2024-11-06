#include <stdbool.h>

static bool isIncreasing(int* nums, int numsSize, int i);

bool canBeIncreasing(int* nums, int numsSize) {
  for (int i = 1; i < numsSize; ++i) {
    if (nums[i] > nums[i - 1]) continue;
    if (++i >= numsSize) return true;
    if (nums[i] > nums[i - 2] && isIncreasing(nums, numsSize, i)) return true;
    if (nums[i] > nums[i - 1] &&
        (i < 3 || nums[i - 1] > nums[i - 3]) &&
        isIncreasing(nums, numsSize, i)) {
      return true;
    }
    return false;
  }
  return true;
}

static bool isIncreasing(int* nums, int numsSize, int i) {
  while (++i < numsSize) {
    if (nums[i] <= nums[i - 1]) return false;
  }
  return true;
}
