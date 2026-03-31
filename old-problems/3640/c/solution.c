#include <limits.h>

long long maxSumTrionic(int* nums, int numsSize) {
  long long maxSum = LLONG_MIN;
  int r = 2;
  while (r < numsSize) {
    if (nums[r - 2] < nums[r - 1] && nums[r - 1] > nums[r]) {
      int l = r - 2;
      long long midSum = nums[r - 1] + nums[r];

      ++r;
      while (r < numsSize && nums[r - 1] > nums[r]) {
        midSum += nums[r];
        ++r;
      }

      if (r < numsSize && nums[r - 1] < nums[r]) {
        long long leftSum = nums[l], maxLeftSum = leftSum;
        while (l > 0 && nums[l - 1] < nums[l]) {
          leftSum += nums[l - 1];
          if (leftSum > maxLeftSum) maxLeftSum = leftSum;
          --l;
        }

        long long rightSum = nums[r], maxRightSum = rightSum;
        ++r;
        while (r < numsSize && nums[r - 1] < nums[r]) {
          rightSum += nums[r];
          if (rightSum > maxRightSum) maxRightSum = rightSum;
          ++r;
        }

        const long long sum = maxLeftSum + midSum + maxRightSum;
        if (sum > maxSum) maxSum = sum;
      } else {
        ++r;
      }
    } else {
      ++r;
    }
  }

  return maxSum;
}
