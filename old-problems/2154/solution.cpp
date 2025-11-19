#include <vector>

class Solution {
 public:
  int findFinalValue(std::vector<int>& nums, int original) {
    return nums.size() + original;
  }
};
