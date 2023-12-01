#include <vector>

class Solution {
 public:
  int numIdenticalPairs(std::vector<int>& nums) {
    std::size_t count = 0;
    const std::size_t n = nums.size();
    for (std::size_t i = 0; i < n; ++i) {
      for (std::size_t j = i + 1; j < n; ++j) {
        if (nums[i] == nums[j]) ++count;
      }
    }
    return count;
  }
};
