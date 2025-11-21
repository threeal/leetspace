#include <stdlib.h>

int compare(const void* a, const void* b) {
  return *(int*)a - *(int*)b;
}

int findFinalValue(int* nums, int numsSize, int original) {
  qsort(nums, numsSize, sizeof(int), compare);

  int i = 0;
  while (1) {
    while (i < numsSize && nums[i] < original) ++i;
    if (i < numsSize && nums[i] == original) {
      original *= 2;
    } else {
      break;
    }
  }

  return original;
}
