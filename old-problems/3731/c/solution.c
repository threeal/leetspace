#include <stdlib.h>

int compare(const void* a, const void* b) {
  return *(int*)a - *(int*)b;
}

int* findMissingElements(int* nums, int numsSize, int* returnSize) {
  qsort(nums, numsSize, sizeof(int), compare);

  int* missings = malloc(
      (nums[numsSize - 1] + 1 - nums[0] - numsSize) * sizeof(int));
  int missingsSize = 0;

  for (int i = 1; i < numsSize; ++i) {
    for (int num = nums[i - 1] + 1; num < nums[i]; ++num) {
      missings[missingsSize++] = num;
    }
  }

  *returnSize = missingsSize;
  return missings;
}
