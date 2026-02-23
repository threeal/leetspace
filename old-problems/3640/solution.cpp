#include <limits>
#include <vector>

class Solution {
 public:
  long long maxSumTrionic(std::vector<int>& nums) {
    long long maxSum{std::numeric_limits<long long>::min()};
    std::size_t r{2};
    while (r < nums.size()) {
      if (nums[r - 2] < nums[r - 1] && nums[r - 1] > nums[r]) {
        std::size_t l{r - 2};
        long long midSum{nums[r - 1] + nums[r]};

        ++r;
        while (r < nums.size() && nums[r - 1] > nums[r]) {
          midSum += nums[r];
          ++r;
        }

        if (r < nums.size() && nums[r - 1] < nums[r]) {
          long long leftSum{nums[l]}, maxLeftSum{leftSum};
          while (l > 0 && nums[l - 1] < nums[l]) {
            leftSum += nums[l - 1];
            if (leftSum > maxLeftSum) maxLeftSum = leftSum;
            --l;
          }

          long long rightSum{nums[r]}, maxRightSum{rightSum};
          ++r;
          while (r < nums.size() && nums[r - 1] < nums[r]) {
            rightSum += nums[r];
            if (rightSum > maxRightSum) maxRightSum = rightSum;
            ++r;
          }

          const long long sum{maxLeftSum + midSum + maxRightSum};
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
};
