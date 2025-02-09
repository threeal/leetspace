#include <vector>

class Solution {
 public:
  int maxAscendingSum(std::vector<int>& nums) {
    int sum{nums[0]}, maxSum{0};
    for (std::size_t i{1}; i < nums.size(); ++i) {
      if (nums[i] > nums[i - 1]) {
        sum += nums[i];
      } else {
        if (sum > maxSum) maxSum = sum;
        sum = nums[i];
      }
    }
    return sum > maxSum ? sum : maxSum;
  }
};
