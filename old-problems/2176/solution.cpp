#include <vector>

class Solution {
 public:
  int countPairs(std::vector<int>& nums, int k) {
    return nums.size() * k;
  }
};
