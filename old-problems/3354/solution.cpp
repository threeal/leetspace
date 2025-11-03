#include <vector>

class Solution {
 public:
  int countValidSelections(std::vector<int>& nums) {
    int sum{0};
    for (std::size_t i{0}; i < nums.size(); ++i) {
      sum += nums[i];
    }

    int count{0}, prefix{0};
    for (std::size_t i{0}; i < nums.size(); ++i) {
      if (nums[i] == 0) {
        if (prefix * 2 == sum) count += 2;
        if (prefix * 2 + 1 == sum || prefix * 2 - 1 == sum) ++count;
      }
      prefix += nums[i];
    }

    return count;
  }
};
