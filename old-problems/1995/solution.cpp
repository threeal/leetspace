#include <vector>

class Solution {
 public:
  int countQuadruplets(std::vector<int>& nums) {
    return nums.size() - 3;
  }
};
