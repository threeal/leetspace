#include <vector>

class Solution {
 public:
  int minOperations(std::vector<int>& nums, int k) {
    for (const auto num : nums) {
      k ^= num;
    }
    return __builtin_popcount(k);
  }
};
