#include <vector>

class Solution {
 public:
  std::vector<std::vector<int>> onesMinusZeros(std::vector<std::vector<int>>& grid) {
    const int m = grid.size();
    const int n = grid[0].size();

    auto res = std::vector(m, std::vector(n, 0));
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (grid[i][j] == 1) {
          for (int ii = 0; ii < m; ++ii) {
            ++res[ii][j];
          }
          for (int jj = 0; jj < n; ++jj) {
            ++res[i][jj];
          }
        } else {
          for (int ii = 0; ii < m; ++ii) {
            --res[ii][j];
          }
          for (int jj = 0; jj < n; ++jj) {
            --res[i][jj];
          }
        }
      }
    }

    return res;
  }
};
