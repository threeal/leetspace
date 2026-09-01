#include <vector>

class Solution {
 public:
  int minimumPrefixLength(std::vector<int>& nums) {
    std::size_t i{nums.size() - 1};
    while (i > 0 && nums[i - 1] < nums[i]) --i;
    return i;
  }
};
