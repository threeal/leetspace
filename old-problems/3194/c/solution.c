#include <limits.h>
#include <stdlib.h>

int compare(const void* a, const void* b) {
  return *(int*)a - *(int*)b;
}

double minimumAverage(int* nums, int numsSize) {
  int minimum = INT_MAX;
  qsort(nums, numsSize, sizeof(int), compare);
  for (int l = 0, r = numsSize - 1; l < r; ++l, --r) {
    if (nums[r] + nums[l] < minimum) minimum = nums[r] + nums[l];
  }
  return minimum / 2.0;
}
