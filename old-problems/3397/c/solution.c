#include <stdlib.h>

int compare(const void* a, const void* b) {
  return *(int*)a - *(int*)b;
}

int maxDistinctElements(int* nums, int numsSize, int k) {
  qsort(nums, numsSize, sizeof(int), compare);

  int count = 1, prev = nums[0] - k;
  for (int i = 1; i < numsSize; ++i) {
    const int num = (nums[i] - k >= prev + 1) ? nums[i] - k : prev + 1;
    if (num <= nums[i] + k) {
      prev = num;
      ++count;
    }
  }

  return count;
}
