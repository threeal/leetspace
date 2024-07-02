#include <limits.h>
#include <stdbool.h>
#include <stdlib.h>

bool find132pattern(int* nums, int numsSize) {
  int j = numsSize;
  int k = INT_MIN;
  for (int i = numsSize - 1; i >= 0; --i) {
    if (nums[i] < k) return true;

    while (j < numsSize && nums[i] > nums[j]) {
      k = nums[j];
      ++j;
    }

    --j;
    nums[j] = nums[i];
  }

  return false;
}
