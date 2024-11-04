#include <stdlib.h>

int compare(const void* a, const void* b) {
  return *(int*)b - *(int*)a;
}

int longestSquareStreak(int* nums, int numsSize) {
  qsort(nums, numsSize, sizeof(int), compare);

  char maxSquare = 1;
  char squares[100001] = {0};
  for (int i = 0; i < numsSize; ++i) {
    if (nums[i] <= 316) {
      squares[nums[i]] = 1 + squares[nums[i] * nums[i]];
      if (squares[nums[i]] > maxSquare) maxSquare = squares[nums[i]];
    } else {
      squares[nums[i]] = 1;
    }
  }

  return maxSquare > 1 ? maxSquare : -1;
}
