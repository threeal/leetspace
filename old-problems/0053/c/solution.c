#include <limits.h>

int maxSubArray(int* nums, int numsSize) {
  int sum = 0, maxSum = INT_MIN;
  for (int i = numsSize - 1; i >= 0; --i) {
    sum += nums[i];
    if (sum > maxSum) maxSum = sum;
    if (sum < 0) sum = 0;
  }
  return maxSum;
}
