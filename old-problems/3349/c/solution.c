#include <stdbool.h>

bool hasIncreasingSubarrays(int* nums, int numsSize, int k) {
  bool prevIncreasing = false;
  int l = 0;
  for (int r = 1; r < numsSize; ++r) {
    if (nums[r] <= nums[r - 1]) {
      if (r - l >= k) {
        if (prevIncreasing || r - l >= k * 2) {
          return true;
        } else {
          prevIncreasing = true;
        }
      } else {
        prevIncreasing = false;
      }
      l = r;
    }
  }
  return prevIncreasing ? numsSize - l >= k : numsSize - l >= k * 2;
}
