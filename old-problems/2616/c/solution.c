#include <stdlib.h>

int compare(const void* a, const void* b) {
  return *(int*)a - *(int*)b;
}

int minimizeMax(int* nums, int numsSize, int p) {
  qsort(nums, numsSize, sizeof(int), compare);
  int left = 0, right = nums[numsSize - 1] - nums[0];
  while (left < right) {
    const int mid = left + (right - left) / 2;
    int pairs = 0;
    for (int i = 1; i < numsSize; ++i) {
      if (nums[i] - nums[i - 1] <= mid) {
        ++pairs;
        ++i;
      }
    }
    if (pairs >= p) {
      right = mid;
    } else {
      left = mid + 1;
    }
  }
  return left;
}
