#include <stdlib.h>

int comp(const void* a, const void* b) {
  return *(int*)a - *(int*)b;
}

int threeSumClosest(int* nums, int numsSize, int target) {
  qsort(nums, numsSize, sizeof(int), comp);

  int closest = nums[0] + nums[1] + nums[2];
  if (closest == target) return target;

  for (int k = 3; k < numsSize; ++k) {
    while (k + 1 < numsSize && nums[k] == nums[k + 1]) ++k;

    int i = 0;
    int j = k - 1;
    while (i < j) {
      const int sum = nums[i] + nums[j] + nums[k];
      if (sum == target) {
        return target;
      }

      if (abs(sum - target) < abs(closest - target)) {
        closest = sum;
      }

      if (sum < target) {
        while (++i < j && nums[i - 1] == nums[i]) continue;
      } else {
        while (--j > i && nums[j] == nums[j + 1]) continue;
      }
    }
  }

  return closest;
}
