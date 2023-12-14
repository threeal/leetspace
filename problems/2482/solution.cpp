#include <vector>

class Solution {
 public:
  std::vector<std::vector<int>> onesMinusZeros(std::vector<std::vector<int>>& grid) {
    const int m = grid.size();
    const int n = grid[0].size();

    // Calculate the total count of elements with a value of one in each row and column.
    std::vector<int> oneRow(m);
    std::vector<int> oneCol(n);
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (grid[i][j] == 1) {
          ++oneRow[i];
          ++oneCol[j];
        }
      }
    }

    // Modify the given grid.
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        // Given that zeroRow[i] + zeroCol[j] = m + n - oneRow[i] - oneCol[j].
        grid[i][j] = 2 * (oneRow[i] + oneCol[j]) - m - n;
      }
    }

    return grid;
  }
};
