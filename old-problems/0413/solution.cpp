#include <vector>

class Solution {
 public:
  int numberOfArithmeticSlices(std::vector<int>& nums) {
    int count{0}, length{1};
    for (std::size_t i{2}; i < nums.size(); ++i) {
      if (nums[i] - nums[i - 1] == nums[i - 1] - nums[i - 2]) {
        count += length;
        ++length;
      } else {
        length = 1;
      }
    }
    return count;
  }
};
