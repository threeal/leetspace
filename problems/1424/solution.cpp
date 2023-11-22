#include <algorithm>
#include <list>
#include <vector>

class Solution {
 public:
  std::vector<int> findDiagonalOrder(std::vector<std::vector<int>>& nums) {
    size_t diagonalCount = 0;
    for (size_t y = 0; y < nums.size(); ++y) {
      diagonalCount = std::max(diagonalCount, y + nums[y].size());
    }

    std::vector<std::list<int>> diagonals(diagonalCount);
    for (size_t y = 0; y < nums.size(); ++y) {
      for (size_t x = 0; x < nums[y].size(); ++x) {
        diagonals[y + x].push_front(nums[y][x]);
      }
    }

    std::vector<int> result;
    for (const auto& diagonal : diagonals) {
      for (const auto num : diagonal) {
        result.push_back(num);
      }
    }

    return result;
  }
};
