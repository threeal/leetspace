#include <vector>

class Solution {
 public:
  int maximizeSum(std::vector<int>& nums, int k) {
    return nums.front() + k;
  }
};
