#include <stdlib.h>

int compare(const void* a, const void* b) {
  return *(int*)a - *(int*)b;
}

int maximumBeauty(int* nums, int numsSize, int k) {
  qsort(nums, numsSize, sizeof(int), compare);

  int max = 1;
  for (int i = 0, j = 1; j < numsSize; ++i) {
    while (j < numsSize && nums[j] <= nums[i] + k * 2) ++j;
    if (j - i > max) max = j - i;
  }
  return max;
}
