#include <vector>

class Solution {
 public:
  int countPairs(std::vector<int>& nums, int target) {
    int count{0};
    for (std::size_t i{0}; i < nums.size(); ++i) {
      for (std::size_t j{i + 1}; j < nums.size(); ++j) {
        if (nums[i] + nums[j] < target) ++count;
      }
    }
    return count;
  }
};
