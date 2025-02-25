#include <stdlib.h>

int compare(const void* a, const void* b) {
  return *(int*)a - *(int*)b;
}

int longestConsecutive(int* nums, int numsSize) {
  if (numsSize == 0) return 0;
  qsort(nums, numsSize, sizeof(int), compare);
  int consecutive = 1, maxConsecutive = 1;
  for (int i = 1; i < numsSize; ++i) {
    if (nums[i] == nums[i - 1]) continue;
    if (nums[i - 1] + 1 == nums[i]) {
      ++consecutive;
    } else {
      if (consecutive > maxConsecutive) maxConsecutive = consecutive;
      consecutive = 1;
    }
  }
  return consecutive > maxConsecutive ? consecutive : maxConsecutive;
}
