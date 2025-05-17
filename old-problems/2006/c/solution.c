#include <stdlib.h>

int compare(const void* a, const void* b) {
  return *(int*)a - *(int*)b;
}

int countKDifference(int* nums, int numsSize, int k) {
  int count = 0;
  qsort(nums, numsSize, sizeof(int), compare);
  for (int l = 0, r = 0, i = 1; i < numsSize; ++i) {
    while (r < i && nums[r] + k <= nums[i]) ++r;
    while (l < r && nums[l] + k < nums[i]) ++l;
    count += r - l;
  }
  return count;
}
