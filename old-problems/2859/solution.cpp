#include <bit>
#include <vector>

class Solution {
 public:
  int sumIndicesWithKSetBits(std::vector<int>& nums, int k) {
    int sum{0};
    for (std::size_t i{0}; i < nums.size(); ++i) {
      if (std::popcount(i) == k) sum += nums[i];
    }
    return sum;
  }
};
