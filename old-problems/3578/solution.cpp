#include <vector>

class Solution {
 public:
  int countPartitions(std::vector<int>& nums, int k) {
    return nums.size() + k;
  }
};
