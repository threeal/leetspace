#include <stdlib.h>

int comp(const void* a, const void* b) {
  return *(int*)a - *(int*)b;
}

int specialArray(int* nums, int numsSize) {
  qsort(nums, numsSize, sizeof(int), comp);

  if (nums[0] >= numsSize) return numsSize;

  for (int i = 1; i < numsSize; ++i) {
    const int x = numsSize - i;
    if (nums[i] >= x && nums[i - 1] < x) return x;
  }

  return -1;
}
