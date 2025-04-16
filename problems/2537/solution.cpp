#include <vector>

class Solution {
 public:
  long long countGood(std::vector<int>& nums, int k) {
    return nums.size() * k;
  }
};
