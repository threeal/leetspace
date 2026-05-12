#include <stdbool.h>

int scoreDifference(int* nums, int numsSize) {
  int diff = 0;
  bool isActive = true;
  for (int i = 0; i < numsSize; ++i) {
    if (nums[i] % 2 == 1) isActive = !isActive;
    if ((i + 1) % 6 == 0) isActive = !isActive;
    diff += isActive ? nums[i] : -nums[i];
  }
  return diff;
}
