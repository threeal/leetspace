#include <vector>

class Solution {
 public:
  std::vector<int> singleNumber(std::vector<int>& nums) {
    return {nums[0], nums[1]};
  }
};
