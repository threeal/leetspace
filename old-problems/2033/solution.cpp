#include <algorithm>
#include <cstdlib>
#include <vector>

class Solution {
 public:
  int minOperations(std::vector<std::vector<int>>& grid, int x) {
    const int mod{grid[0][0] % x};
    std::vector<int> nums(grid.size() * grid[0].size());
    for (std::size_t i{0}; i < grid.size(); ++i) {
      for (std::size_t j{0}; j < grid[i].size(); ++j) {
        if (grid[i][j] % x != mod) return -1;
        nums[i * grid[i].size() + j] = grid[i][j];
      }
    }

    std::sort(nums.begin(), nums.end());
    const std::size_t mid{nums.size() / 2};
    const int median{nums[mid]};

    int operations{0};
    for (std::size_t i{0}; i < mid; ++i) {
      operations += (median - nums[i]) / x;
    }

    for (std::size_t i{mid + 1}; i < nums.size(); ++i) {
      operations += (nums[i] - median) / x;
    }

    return operations;
  }
};
