#include <stdbool.h>

bool check(int* nums, int numsSize) {
  for (int i = 1; i < numsSize; ++i) {
    if (nums[i] < nums[i - 1]) {
      if (nums[i] > nums[0]) return false;
      for (++i; i < numsSize; ++i) {
        if (nums[i] > nums[0] || nums[i] < nums[i - 1]) return false;
      }
    }
  }
  return true;
}
