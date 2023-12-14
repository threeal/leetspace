#include <vector>

class Solution {
 public:
  std::vector<std::vector<int>> onesMinusZeros(std::vector<std::vector<int>>& grid) {
    const int m = grid.size();
    const int n = grid[0].size();

    std::vector<int> oneRow(m);
    std::vector<int> oneCol(n);

    std::vector<int> zeroRow(m);
    std::vector<int> zeroCol(n);

    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (grid[i][j] == 1) {
          ++oneRow[i];
          ++oneCol[j];
        } else {
          ++zeroRow[i];
          ++zeroCol[j];
        }
      }
    }

    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        grid[i][j] = oneRow[i] + oneCol[j] - zeroRow[i] - zeroCol[j];
      }
    }

    return grid;
  }
};
