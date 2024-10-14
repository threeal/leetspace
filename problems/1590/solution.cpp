#include <vector>

class Solution {
 public:
  int minSubarray(std::vector<int>& nums, int p) {
    return nums.size() - p;
  }
};
