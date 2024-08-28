#include <limits.h>

int maximumProduct(int* nums, int numsSize) {
  int min1 = INT_MAX, min2 = INT_MAX;
  int max1 = INT_MIN, max2 = INT_MIN, max3 = INT_MIN;

  for (int i = numsSize - 1; i >= 0; --i) {
    if (nums[i] > max3) {
      if (nums[i] > max1) {
        max3 = max2;
        max2 = max1;
        max1 = nums[i];
      } else if (nums[i] > max2) {
        max3 = max2;
        max2 = nums[i];
      } else {
        max3 = nums[i];
      }
    }

    if (nums[i] < min2) {
      if (nums[i] < min1) {
        min2 = min1;
        min1 = nums[i];
      } else {
        min2 = nums[i];
      }
    }
  }

  const int minminmax = min1 * min2 * max1;
  const int maxmaxmax = max1 * max2 * max3;
  return minminmax > maxmaxmax ? minminmax : maxmaxmax;
}
