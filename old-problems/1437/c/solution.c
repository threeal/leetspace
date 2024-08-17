#include <stdbool.h>

bool kLengthApart(int* nums, int numsSize, int k) {
  int prev = numsSize + k;
  for (int i = numsSize - 1; i >= 0; --i) {
    if (nums[i] != 0) {
      if (prev - i <= k) return false;
      prev = i;
    }
  }
  return true;
}
