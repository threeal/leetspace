#include <stdbool.h>
#include <stdlib.h>

int compare(const void* a, const void* b) {
  return (long long)*(int*)a - (long long)*(int*)b;
}

bool findSubarrays(int* nums, int numsSize) {
  for (int i = 1; i < numsSize; ++i) nums[i - 1] += nums[i];
  --numsSize;

  qsort(nums, numsSize, sizeof(int), compare);

  for (int i = 1; i < numsSize; ++i) {
    if (nums[i - 1] == nums[i]) return true;
  }

  return false;
}
