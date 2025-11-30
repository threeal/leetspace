#include <stdlib.h>

int compare(const void* a, const void* b) {
  return *(int*)b - *(int*)a;
}

int* minSubsequence(int* nums, int numsSize, int* returnSize) {
  qsort(nums, numsSize, sizeof(int), compare);

  int n = 0, sum = 0, restSum = 0;
  for (int i = 0; i < numsSize; ++i) restSum += nums[i];

  while (sum <= restSum) {
    sum += nums[n];
    restSum -= nums[n];
    ++n;
  }

  *returnSize = n;
  return nums;
}
