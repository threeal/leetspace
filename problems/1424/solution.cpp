// The solution can be done by categorizing each number to its diagonal.
// After that, merge all numbers in the diagonals into a single array.

#include <algorithm>
#include <list>
#include <vector>

class Solution {
 public:
  std::vector<int> findDiagonalOrder(std::vector<std::vector<int>>& nums) {
    // Calculate the maximum diagonal count.
    std::size_t diagonalCount = 0;
    for (std::size_t y = 0; y < nums.size(); ++y) {
      diagonalCount = std::max(diagonalCount, y + nums[y].size());
    }

    // Push each number into its diagonal.
    std::vector<std::list<int>> diagonals(diagonalCount);
    for (std::size_t y = 0; y < nums.size(); ++y) {
      for (std::size_t x = 0; x < nums[y].size(); ++x) {
        diagonals[y + x].push_front(nums[y][x]);
      }
    }

    // Merge all numbers in the diagonals into a single array.
    std::vector<int> result;
    for (const auto& diagonal : diagonals) {
      for (const auto num : diagonal) {
        result.push_back(num);
      }
    }

    return result;
  }
};
