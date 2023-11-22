#include <vector>

class Solution {
 public:
  std::vector<int> findDiagonalOrder(std::vector<std::vector<int>>& nums) {
    size_t numsCount = 0;
    for (const auto& subnums : nums) {
      numsCount += subnums.size();
    }

    std::vector<int> result(numsCount);

    size_t i = 0;
    size_t y = 0;
    while (i < numsCount) {
      for (size_t x = 0; x <= y; ++x) {
        if (y - x >= nums.size()) continue;
        if (x >= nums[y - x].size()) continue;
        result[i++] = nums[y - x][x];
      }
      ++y;
    }

    return result;
  }
};
