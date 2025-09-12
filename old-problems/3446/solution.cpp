#include <algorithm>
#include <vector>

class Solution {
 public:
  std::vector<std::vector<int>> sortMatrix(
      std::vector<std::vector<int>>& grid) {
    const std::size_t m{grid.size()};
    const std::size_t n{grid[0].size()};

    std::vector<int> arr(std::min(m, n));
    for (std::size_t i{0}; i < m; ++i) {
      std::size_t k{0};
      while (i + k < m && k < n) {
        arr[k] = grid[i + k][k];
        ++k;
      }

      std::sort(arr.begin(), arr.begin() + k, std::greater<int>());

      while (k > 0) {
        --k;
        grid[i + k][k] = arr[k];
      }
    }

    for (std::size_t j{1}; j < n; ++j) {
      std::size_t k{0};
      while (k < m && j + k < n) {
        arr[k] = grid[k][j + k];
        ++k;
      }

      std::sort(arr.begin(), arr.begin() + k);

      while (k > 0) {
        --k;
        grid[k][j + k] = arr[k];
      }
    }

    return grid;
  }
};
