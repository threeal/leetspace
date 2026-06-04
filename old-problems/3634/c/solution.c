#include <stdlib.h>

int compare(const void* a, const void* b) {
  return *(int*)a - *(int*)b;
}

int minRemoval(int* nums, int numsSize, int k) {
  qsort(nums, numsSize, sizeof(int), compare);
  int maxSize = 0;
  for (int l = 0, r = 0; r < numsSize; ++r) {
    while (nums[l] < (nums[r] + k - 1) / k) ++l;
    if (r + 1 - l > maxSize) maxSize = r + 1 - l;
  }
  return numsSize - maxSize;
}
