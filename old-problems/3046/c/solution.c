#include <stdbool.h>

bool isPossibleToSplit(int* nums, int numsSize) {
  char freqs[101] = {0};
  for (int i = 0; i < numsSize; ++i) {
    if (++freqs[nums[i]] == 3) return false;
  }
  return true;
}
