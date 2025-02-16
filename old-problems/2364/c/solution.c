#include <stdlib.h>

int compare(const void* a, const void* b) {
  return *(int*)a - *(int*)b;
}

long long countBadPairs(int* nums, int numsSize) {
  for (int i = 0; i < numsSize; ++i) nums[i] -= i;
  qsort(nums, numsSize, sizeof(int), compare);

  long long total = numsSize;
  total = total * (total - 1) / 2;

  long long freq = 1;
  for (int i = 1; i < numsSize; ++i) {
    if (nums[i] == nums[i - 1]) {
      ++freq;
    } else {
      total -= freq * (freq - 1) / 2;
      freq = 1;
    }
  }

  return total - freq * (freq - 1) / 2;
}
