#include <vector>

class Solution {
 public:
  int minOperations(std::vector<int>& nums) {
    int operations{0};
    for (std::size_t i{2}; i < nums.size(); ++i) {
      if (nums[i - 2] == 0) {
        ++operations;
        nums[i - 1] ^= 1;
        nums[i] ^= 1;
      }
    }

    return nums[nums.size() - 1] == 1 && nums[nums.size() - 2] == 1
        ? operations
        : -1;
  }
};
