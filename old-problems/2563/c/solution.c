#include <stdlib.h>

int compare(const void* a, const void* b) {
  return *(int*)a - *(int*)b;
}

long long countFairPairs(int* nums, int numsSize, int lower, int upper) {
  qsort(nums, numsSize, sizeof(int), compare);

  long long count = 0;
  int l = 0, r = numsSize - 1;
  while (l < r) {
    if (nums[l] + nums[r] > upper) {
      --r;
    } else {
      count += r - l;
      ++l;
    }
  }

  l = 0, r = numsSize - 1;
  while (l < r) {
    if (nums[l] + nums[r] >= lower) {
      --r;
    } else {
      count -= r - l;
      ++l;
    }
  }

  return count;
}
