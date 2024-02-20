#include <vector>

class Solution {
 public:
  int missingNumber(std::vector<int>& nums) {
    const int n = nums.size();

    auto total = (n * n + n) / 2;
    for (const auto num : nums) {
      total -= num;
    }

    return total;
  }
};
