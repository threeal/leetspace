#include <stdlib.h>

int compare(const void* a, const void* b) {
  return *(int*)a - *(int*)b;
}

int findLHS(int* nums, int numsSize) {
  qsort(nums, numsSize, sizeof(int), compare);

  int maxLen = 0;
  for (int l = 0, r = 0; r < numsSize; ++r) {
    while (nums[l] + 1 < nums[r]) ++l;
    if (nums[l] + 1 == nums[r]) {
      if (r + 1 - l > maxLen) maxLen = r + 1 - l;
    }
  }

  return maxLen;
}
