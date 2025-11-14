#include <algorithm>
#include <numeric>
#include <vector>

class Solution {
 public:
  int minOperations(std::vector<int>& nums) {
    int ones{0};
    for (const int num : nums) {
      if (num == 1) ++ones;
    }

    if (ones > 0) return nums.size() - ones;

    std::size_t minLen{nums.size() + 1};
    for (std::size_t i{0}; i < nums.size(); ++i) {
      int minNum{nums[i]};

      std::size_t maxJ{std::min(nums.size(), i + minLen)};
      for (std::size_t j{i + 1}; j < maxJ; ++j) {
        minNum = std::gcd(minNum, nums[j]);
        if (minNum == 1) {
          minLen = j + 1 - i;
          break;
        }
      }
    }

    return minLen <= nums.size() ? nums.size() + minLen - 2 : -1;
  }
};
