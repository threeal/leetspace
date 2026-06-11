#include <vector>

class Solution {
 public:
  std::vector<std::vector<int>> constructProductMatrix(
      std::vector<std::vector<int>>& grid) {
    std::vector<std::vector<int>> output(
        grid.size(), std::vector<int>(grid[0].size()));

    int prefix{1};
    for (std::size_t i{0}; i < grid.size(); ++i) {
      for (std::size_t j{0}; j < grid[0].size(); ++j) {
        grid[i][j] %= 12345;
        output[i][j] = prefix;
        prefix = (prefix * grid[i][j]) % 12345;
      }
    }

    int suffix{1};
    for (std::size_t i{grid.size()}; i > 0;) {
      --i;
      for (std::size_t j{grid[i].size()}; j > 0;) {
        --j;
        output[i][j] = (output[i][j] * suffix) % 12345;
        suffix = (suffix * grid[i][j]) % 12345;
      }
    }

    return output;
  }
};
