#include <vector>

class Solution {
 public:
  int singleNumber(std::vector<int>& nums) {
    int sum{0};
    for (const auto num : nums) sum ^= num;
    return sum;
  }
};
