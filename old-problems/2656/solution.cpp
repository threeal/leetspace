#include <vector>

class Solution {
 public:
  int maximizeSum(std::vector<int>& nums, int k) {
    int max{nums[0]};
    for (std::size_t i{1}; i < nums.size(); ++i) {
      if (nums[i] > max) max = nums[i];
    }
    return k * (2 * max + k - 1) / 2;
  }
};
