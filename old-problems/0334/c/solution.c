#include <limits.h>
#include <stdbool.h>

bool increasingTriplet(int* nums, int numsSize) {
  int a = INT_MAX;
  int b = INT_MAX;
  for (int i = 0; i < numsSize; ++i) {
    if (nums[i] <= a) {
      a = nums[i];
    } else if (nums[i] <= b) {
      b = nums[i];
    } else {
      return true;
    }
  }
  return false;
}
