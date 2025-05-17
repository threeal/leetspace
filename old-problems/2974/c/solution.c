#include <stdlib.h>

int compare(const void* a, const void* b) {
  return *(int*)a - *(int*)b;
}

int* numberGame(int* nums, int numsSize, int* returnSize) {
  qsort(nums, numsSize, sizeof(int), compare);
  for (int i = 1; i < numsSize; i += 2) {
    const int temp = nums[i];
    nums[i] = nums[i - 1];
    nums[i - 1] = temp;
  }
  *returnSize = numsSize;
  return nums;
}
