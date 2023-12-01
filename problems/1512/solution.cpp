#include <vector>

class Solution {
 public:
  int numIdenticalPairs(std::vector<int>& nums) {
    size_t count = 0;
    const size_t n = nums.size();
    for (size_t i = 0; i < n; ++i) {
      for (size_t j = i + 1; j < n; ++j) {
        if (nums[i] == nums[j]) ++count;
      }
    }
    return count;
  }
};
