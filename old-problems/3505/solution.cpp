#include <vector>

class Solution {
 public:
  long long minOperations(std::vector<int>& nums, int x, int k) {
    return static_cast<long long>(nums.size()) + x + k;
  }
};
