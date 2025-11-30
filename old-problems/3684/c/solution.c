#include <stdlib.h>

int compare(const void* a, const void* b) {
  return *(int*)b - *(int*)a;
}

int* maxKDistinct(int* nums, int numsSize, int k, int* returnSize) {
  qsort(nums, numsSize, sizeof(int), compare);

  int n = 1;
  for (int i = 1; i < numsSize && n < k; ++i) {
    if (nums[i] != nums[i - 1]) nums[n++] = nums[i];
  }

  *returnSize = n;
  return nums;
}
