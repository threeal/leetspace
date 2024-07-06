#include <stdlib.h>

int maximumJumps(int* nums, int numsSize, int target) {
  int* jumps = malloc(numsSize * sizeof(int));
  jumps[numsSize - 1] = 0;

  for (int i = numsSize - 2; i >= 0; --i) {
    jumps[i] = -2;
    for (int j = numsSize - 1; j > i; --j) {
      if (jumps[j] < 0 || abs(nums[j] - nums[i]) > target) continue;
      if (jumps[j] > jumps[i]) jumps[i] = jumps[j];
    }
    ++jumps[i];
  }

  const int maxJump = jumps[0];
  free(jumps);

  return maxJump;
}
