#include <limits>
#include <vector>

class Solution {
 public:
  int maxSubArray(std::vector<int>& nums) {
    int sum{0}, maxSum{std::numeric_limits<int>::min()};
    for (const auto num : nums) {
      sum += num;
      if (sum > maxSum) maxSum = sum;
      if (sum < 0) sum = 0;
    }
    return maxSum;
  }
};
