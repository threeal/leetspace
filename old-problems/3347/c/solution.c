#include <stdlib.h>

int compare(const void* a, const void* b) {
  return *(int*)a - *(int*)b;
}

int maxFrequency(int* nums, int numsSize, int k, int numOperations) {
  qsort(nums, numsSize, sizeof(int), compare);

  int maxFreq = 0, il = 0, i = 0, ih = 0, l = 0, m = 0, r = 0;
  while (il < numsSize || i < numsSize || ih < numsSize) {
    int num = nums[numsSize - 1] + k;
    if (il < numsSize && nums[il] - k < num) num = nums[il] - k;
    if (i < numsSize && nums[i] < num) num = nums[i];
    if (ih < numsSize && nums[ih] + k < num) num = nums[ih] + k;

    while (m < numsSize && nums[m] < num) ++m;

    int equals = 0;
    while (m < numsSize && nums[m] == num) ++equals, ++m;

    while (nums[l] < num - k) ++l;
    while (r < numsSize && nums[r] <= num + k) ++r;

    int freq = r - l <= equals + numOperations ? r - l : equals + numOperations;
    if (freq > maxFreq) maxFreq = freq;

    while (il < numsSize && nums[il] - k == num) ++il;
    while (i < numsSize && nums[i] == num) ++i;
    while (ih < numsSize && nums[ih] + k == num) ++ih;
  }

  return maxFreq;
}
