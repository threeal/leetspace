#include <stdlib.h>

int compare(const void* a, const void* b) {
  return *(int*)a - *(int*)b;
}

int minMoves2(int* nums, int numsSize) {
  qsort(nums, numsSize, sizeof(int), compare);

  int moves = 0;
  const int mid = numsSize / 2;

  for (int i = 0; i < mid; ++i) {
    moves += nums[mid] - nums[i];
  }

  for (int i = mid + 1; i < numsSize; ++i) {
    moves += nums[i] - nums[mid];
  }

  return moves;
}
