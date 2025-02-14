#include <algorithm>
#include <vector>

class Solution {
 public:
  int maximumGap(std::vector<int>& nums) {
    std::sort(nums.begin(), nums.end());
    int maxGap{0};
    for (std::size_t i{1}; i < nums.size(); ++i) {
      maxGap = std::max(maxGap, nums[i] - nums[i - 1]);
    }
    return maxGap;
  }
};
