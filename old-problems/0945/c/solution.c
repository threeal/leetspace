#include <stdlib.h>

int comp(const void* a, const void* b) {
  return *(int*)a - *(int*)b;
}

int minIncrementForUnique(int* nums, int numsSize) {
  qsort(nums, numsSize, sizeof(int), comp);

  int moves = 0;
  int minAvailable = 0;
  for (int i = 0; i < numsSize; ++i) {
    if (minAvailable > nums[i]) {
      moves += minAvailable - nums[i];
      ++minAvailable;
    } else {
      minAvailable = nums[i] + 1;
    }
  }

  return moves;
}
