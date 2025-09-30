#include <stdbool.h>

int countHillValley(int* nums, int numsSize) {
  int count = 0;
  bool increasing = false, decreasing = false;
  for (int i = 1; i < numsSize; ++i) {
    if (nums[i] > nums[i - 1]) {
      if (decreasing) ++count;
      increasing = true;
      decreasing = false;
    } else if (nums[i] < nums[i - 1]) {
      if (increasing) ++count;
      decreasing = true;
      increasing = false;
    }
  }
  return count;
}
