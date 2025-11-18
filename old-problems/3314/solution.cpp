#include <vector>

class Solution {
 public:
  std::vector<int> minBitwiseArray(std::vector<int>& nums) {
    for (auto& num : nums) {
      num = num != 2
          ? num - ((num + 1) & (-num - 1)) / 2
          : -1;
    }
    return nums;
  }
};
