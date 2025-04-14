#include <stdlib.h>

int* resultsArray(int* nums, int numsSize, int k, int* returnSize) {
  if (--k == 0) {
    *returnSize = numsSize;
    return nums;
  }

  int count = 0;
  for (int i = 1; i < k; ++i) {
    if (nums[i - 1] + 1 == nums[i]) {
      ++count;
    } else {
      count = 0;
    }
  }

  int* output = malloc((numsSize - k) * sizeof(int));
  for (int i = k; i < numsSize; ++i) {
    if (nums[i - 1] + 1 == nums[i]) {
      output[i - k] = ++count >= k ? nums[i] : -1;
    } else {
      count = 0;
      output[i - k] = -1;
    }
  }

  *returnSize = numsSize - k;
  return output;
}
