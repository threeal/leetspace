#include <vector>

class Solution {
 public:
  int minMoves(std::vector<int>& nums) {
    int sum{nums[0]}, min{nums[0]};
    for (std::size_t i{1}; i < nums.size(); ++i) {
      sum += nums[i];
      if (nums[i] < min) min = nums[i];
    }
    return sum - min * nums.size();
  }
};
