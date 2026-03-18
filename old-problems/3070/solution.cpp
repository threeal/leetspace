#include <vector>

class Solution {
 public:
  int countSubmatrices(std::vector<std::vector<int>>& grid, int k) {
    int count{0};
    if (grid[0][0] <= k) ++count;

    for (std::size_t i{1}; i < grid[0].size(); ++i) {
      grid[0][i] += grid[0][i - 1];
      if (grid[0][i] <= k) {
        ++count;
      } else {
        break;
      }
    }

    for (std::size_t i{1}; i < grid.size(); ++i) {
      grid[i][0] += grid[i - 1][0];
      if (grid[i][0] <= k) {
        ++count;
        for (std::size_t j{1}; j < grid[i].size(); ++j) {
          grid[i][j] += grid[i - 1][j] + grid[i][j - 1] - grid[i - 1][j - 1];
          if (grid[i][j] <= k) {
            ++count;
          } else {
            break;
          }
        }
      } else {
        break;
      }
    }

    return count;
  }
};
