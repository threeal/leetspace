#include <vector>

class Solution {
 public:
  int alternatingSum(std::vector<int>& nums) {
    int sum{0};
    for (std::size_t i{0}; i < nums.size(); ++i) {
      sum += nums[i];
      if (++i == nums.size()) break;
      sum -= nums[i];
    }
    return sum;
  }
};
