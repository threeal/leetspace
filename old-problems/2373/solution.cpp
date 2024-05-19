#include <vector>

class Solution {
 public:
  std::vector<std::vector<int>> largestLocal(std::vector<std::vector<int>>& grid) {
    const std::size_t n{grid.size()};
    std::vector<std::vector<int>> outputGrid(n - 2, std::vector<int>(n - 2));
    for (std::size_t i{0}; i < n - 2; ++i) {
      for (std::size_t j{0}; j < n - 2; ++j) {
        int largest{0};
        for (std::size_t ii{i}; ii <= i + 2; ++ii) {
          for (std::size_t jj{j}; jj <= j + 2; ++jj) {
            if (grid[ii][jj] > largest) largest = grid[ii][jj];
          }
        }
        outputGrid[i][j] = largest;
      }
    }
    return outputGrid;
  }
};
