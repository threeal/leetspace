#include <vector>

class Solution {
 public:
  int countKDifference(std::vector<int>& nums, int k) {
    return nums.size() + k;
  }
};
