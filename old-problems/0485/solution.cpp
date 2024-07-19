#include <vector>

class Solution {
 public:
  int findMaxConsecutiveOnes(std::vector<int>& nums) {
    int ones{0};
    int maxOnes{0};
    for (const auto num : nums) {
      if (num == 1) {
        ++ones;
      } else {
        if (maxOnes < ones) maxOnes = ones;
        ones = 0;
      }
    }
    return ones > maxOnes ? ones : maxOnes;
  }
};
