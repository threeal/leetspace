#include <stdlib.h>

int compare(const void* a, const void* b) {
  return *(int*)a - *(int*)b;
}

int maxFrequency(int* nums, int numsSize, int k, int numOperations) {
  qsort(nums, numsSize, sizeof(int), compare);

  int maxFreq = 0, l = 0, i = 0, r = 0;
  for (int num = nums[0]; num <= nums[numsSize - 1]; ++num) {
    while (nums[i] < num) ++i;

    int equals = 0;
    while (i < numsSize && nums[i] == num) ++equals, ++i;

    while (nums[l] < num - k) ++l;
    while (r < numsSize && nums[r] <= num + k) ++r;

    const int freq = r - l < equals + numOperations
        ? r - l
        : equals + numOperations;

    if (freq > maxFreq) maxFreq = freq;
  }

  return maxFreq;
}
