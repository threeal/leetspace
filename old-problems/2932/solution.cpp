#include <algorithm>
#include <cstdlib>
#include <vector>

class Solution {
 public:
  int maximumStrongPairXor(std::vector<int>& nums) {
    int max{0};
    for (std::size_t i{0}; i < nums.size(); ++i) {
      for (std::size_t j{i}; j < nums.size(); ++j) {
        if (std::abs(nums[j] - nums[i]) <= std::min(nums[i], nums[j]) &&
            (nums[i] ^ nums[j]) > max) {
          max = nums[i] ^ nums[j];
        }
      }
    }
    return max;
  }
};
