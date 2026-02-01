#include <vector>

class Solution {
 public:
  int minimumCost(std::vector<int>& nums) {
    int a{nums[1] < nums[2] ? nums[1] : nums[2]};
    int b{nums[1] < nums[2] ? nums[2] : nums[1]};
    for (std::size_t i{3}; i < nums.size(); ++i) {
      if (nums[i] < a) {
        b = a;
        a = nums[i];
      } else if (nums[i] < b) {
        b = nums[i];
      }
    }
    return nums[0] + a + b;
  }
};
