#include <vector>

class Solution {
 public:
  int subarraySum(std::vector<int>& nums) {
    int sum{nums[0]};
    for (std::size_t i{1}; i < nums.size(); ++i) {
      if (nums[i] < static_cast<int>(i)) {
        sum -= nums[i - nums[i] - 1];
      }
      nums[i] += nums[i - 1];
      sum += nums[i];
    }
    return sum;
  }
};
