#include <vector>

class Solution {
 public:
  int maximumDifference(std::vector<int>& nums) {
    int diff{-1}, min{nums[0]};
    for (std::size_t i{1}; i < nums.size(); ++i) {
      if (nums[i] == min) continue;
      if (nums[i] < min) {
        min = nums[i];
      } else if (nums[i] - min > diff) {
        diff = nums[i] - min;
      }
    }
    return diff;
  }
};
