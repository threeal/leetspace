#include <vector>

class Solution {
 public:
  int missingMultiple(std::vector<int>& nums, int k) {
    return nums.size() + k;
  }
};
