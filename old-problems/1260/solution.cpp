#include <vector>

class Solution {
 public:
  std::vector<std::vector<int>> shiftGrid(
      std::vector<std::vector<int>>& grid, int k) {
    std::vector<std::vector<int>> out{grid};

    const std::size_t n{grid[0].size()};
    const std::size_t mn{grid.size() * n};
    for (std::size_t i{0}; i < mn; ++i) {
      const std::size_t j{(i + k) % mn};
      out[j / n][j % n] = grid[i / n][i % n];
    }

    return out;
  }
};
