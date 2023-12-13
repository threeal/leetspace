#include <vector>

class Solution {
 public:
  int numSpecial(std::vector<std::vector<int>>& mat) {
    const int m = mat.size();
    const int n = mat[0].size();

    std::vector<int> rows(m, 0);
    std::vector<int> cols(n, 0);
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (mat[i][j] == 1) {
          ++rows[i];
          ++cols[j];
        }
      }
    }

    int sumRow = 0;
    for (const auto row : rows) {
      if (row == 1) ++sumRow;
    }

    int sumCol = 0;
    for (const auto col : cols) {
      if (col == 1) ++sumCol;
    }

    return std::min(sumRow, sumCol);
  }
};
