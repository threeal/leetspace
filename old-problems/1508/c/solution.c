#include <stdlib.h>

int compare(const void* a, const void* b) {
  return *(int*)a - *(int*)b;
}

int rangeSum(int* nums, int numsSize, int n, int left, int right) {
  int sumsSize = (n * (n + 1)) / 2;
  int* sums = malloc(sumsSize * sizeof(int));
  int* it = sums;

  for (int i = 0; i < numsSize; ++i) {
    for (int j = 0; j < i; ++j) {
      nums[j] += nums[i];
      *it = nums[j];
      ++it;
    }

    *it = nums[i];
    ++it;
  }

  qsort(sums, sumsSize, sizeof(int), compare);

  int sum = 0;
  for (int i = left - 1; i < right; ++i) {
    sum = (sum + sums[i]) % 1000000007;
  }

  return sum;
}
