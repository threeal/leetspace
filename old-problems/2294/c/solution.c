#include <stdlib.h>

int compare(const void* a, const void* b) {
  return *(int*)a - *(int*)b;
}

int partitionArray(int* nums, int numsSize, int k) {
  qsort(nums, numsSize, sizeof(int), compare);
  int count = 0, max = -1;
  for (int i = 0; i < numsSize; ++i) {
    if (nums[i] > max) {
      ++count;
      max = nums[i] + k;
    }
  }
  return count;
}
