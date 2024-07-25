#include <vector>

class Solution {
 public:
  int singleNumber(std::vector<int>& nums) {
    int onces{0};
    int twices{0};
    for (const auto num : nums) {
      onces ^= num & ~twices;
      twices ^= num & ~onces;
    }
    return onces;
  }
};
