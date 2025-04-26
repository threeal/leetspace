#include <vector>

class Solution {
 public:
  std::vector<int> shuffle(std::vector<int>& nums, int n) {
    std::vector<int> output(nums.size());
    for (int i{0}; i < n; ++i) {
      output[i * 2] = nums[i];
      output[i * 2 + 1] = nums[n + i];
    }
    return output;
  }
};
