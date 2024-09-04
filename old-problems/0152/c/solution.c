#include <limits.h>

int maxProduct(int* nums, int numsSize) {
  int max = INT_MIN;

  int left = 1, right = 1;
  for (int l = 0, r = numsSize - 1; r >= 0; ++l, --r) {
    if (left == 0) left = 1;
    left *= nums[l];
    if (left > max) max = left;

    if (right == 0) right = 1;
    right *= nums[r];
    if (right > max) max = right;
  }

  return max;
}
