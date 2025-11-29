#include <stdbool.h>

int maxSum(int* nums, int numsSize) {
  bool exists[101] = {false}, positiveExists = false;
  int maxNegative = -101, sumPositives = 0;
  for (int i = 0; i < numsSize; ++i) {
    if (nums[i] >= 0) {
      positiveExists = true;
      if (!exists[nums[i]]) {
        exists[nums[i]] = true;
        sumPositives += nums[i];
      }
    } else {
      if (nums[i] >= maxNegative) maxNegative = nums[i];
    }
  }

  return positiveExists ? sumPositives : maxNegative;
}
