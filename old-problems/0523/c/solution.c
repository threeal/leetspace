#include <stdbool.h>

bool checkSubarraySum(int* nums, int numsSize, int k) {
  int sum = nums[numsSize - 1];
  for (int i = numsSize - 2; i >= 0; --i) {
    if (nums[i] == 0 && nums[i] == nums[i + 1]) return true;

    sum += nums[i];
    if (sum % k == 0) return true;

    int tempSum = sum;
    for (int j = numsSize - 1; j > i + 1 && tempSum > k; --j) {
      tempSum -= nums[j];
      if (tempSum % k == 0) return true;
    }
  }

  return false;
}
