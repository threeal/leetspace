#include <stdlib.h>

int compare(const void *a, const void *b) {
  return *(int *)a - *(int *)b;
}

int smallestDistancePair(int *nums, int numsSize, int k) {
  qsort(nums, numsSize, sizeof(int), compare);

  int low = 0;
  int high = nums[numsSize - 1] - nums[0];
  while (low < high) {
    const int mid = low + (high - low) / 2;
    int count = 0;
    for (int l = 0, r = 1; r < numsSize; ++r) {
      while (l < r && nums[r] - nums[l] > mid) ++l;
      count += r - l;
    }

    if (count < k) {
      low = mid + 1;
    } else {
      high = mid;
    }
  }

  return low;
}
