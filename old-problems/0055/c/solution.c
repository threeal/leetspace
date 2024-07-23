#include <stdbool.h>

bool canJump(int* nums, int numsSize) {
  if (numsSize <= 1) return true;
  nums[numsSize - 1] = 1;

  int maxJump = 0;
  for (int i = 0; i < numsSize; ++i) {
    --maxJump;
    if (nums[i] == 0) {
      if (maxJump <= 0) return false;
    } else {
      if (nums[i] > maxJump) maxJump = nums[i];
    }
  }

  return true;
}
