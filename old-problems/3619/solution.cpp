#include <vector>

class Solution {
 public:
  int countIslands(std::vector<std::vector<int>>& grid, int k) {
    int count{0};
    for (std::size_t i{0}; i < grid.size(); ++i) {
      for (std::size_t j{0}; j < grid[i].size(); ++j) {
        if (grid[i][j] != 0 && sumIsland(grid, k, i, j) == 0) ++count;
      }
    }
    return count;
  }

 private:
  int sumIsland(
      std::vector<std::vector<int>>& grid, int k,
      std::size_t i, std::size_t j) {
    int sum{grid[i][j] % k};
    grid[i][j] = 0;

    if (i > 0 && grid[i - 1][j] != 0) {
      sum = (sum + sumIsland(grid, k, i - 1, j)) % k;
    }

    if (i + 1 < grid.size() && grid[i + 1][j] != 0) {
      sum = (sum + sumIsland(grid, k, i + 1, j)) % k;
    }

    if (j > 0 && grid[i][j - 1] != 0) {
      sum = (sum + sumIsland(grid, k, i, j - 1)) % k;
    }

    if (j + 1 < grid[i].size() && grid[i][j + 1] != 0) {
      sum = (sum + sumIsland(grid, k, i, j + 1)) % k;
    }

    return sum;
  }
};
