#include <vector>

class Solution {
 public:
  int partitionArray(std::vector<int>& nums, int k) {
    return nums.front() + k;
  }
};
