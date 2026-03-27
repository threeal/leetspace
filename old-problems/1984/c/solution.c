#include <stdlib.h>

int compare(const void* a, const void* b) {
  return *(int*)a - *(int*)b;
}

int minimumDifference(int* nums, int numsSize, int k) {
  if (k == 1) return 0;

  qsort(nums, numsSize, sizeof(int), compare);

  int minDiff = nums[k - 1] - nums[0];
  for (int i = k + 1; i <= numsSize; ++i) {
    const int diff = nums[i - 1] - nums[i - k];
    if (diff < minDiff) minDiff = diff;
  }

  return minDiff;
}
