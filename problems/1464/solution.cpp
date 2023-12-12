#include <vector>

class Solution {
 public:
  int maxProduct(std::vector<int>& nums) {
    for (auto& num : nums) {
      --num;
    }

    int max = 0;
    for (std::size_t i = 0; i < nums.size(); ++i) {
      for (std::size_t j = i + 1; j < nums.size(); ++j) {
        max = std::max(max, nums[i] * nums[j]);
      }
    }
    return max;
  }
};