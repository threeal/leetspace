#include <cstdlib>
#include <vector>

class Solution {
 public:
  int maxAdjacentDistance(std::vector<int>& nums) {
    int max{std::abs(nums.front() - nums.back())};
    for (std::size_t i{1}; i < nums.size(); ++i) {
      const int diff{std::abs(nums[i - 1] - nums[i])};
      if (diff > max) max = diff;
    }
    return max;
  }
};
