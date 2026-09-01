#include <vector>

class Solution {
 public:
  std::vector<std::vector<int>> rotateGrid(
      std::vector<std::vector<int>>& grid, int k) {
    const std::size_t m{grid.size()};
    const std::size_t n{grid[0].size()};

    std::vector<std::vector<int>> out(m, std::vector<int>(n));
    for (std::size_t i{0}; i * 2 < m && i * 2 < n; ++i) {
      const std::size_t

    }

    return out;
  }
};
