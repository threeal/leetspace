#include <vector>

class Solution {
 public:
  std::vector<std::vector<int>> generate(int numRows) {
    std::vector<std::vector<int>> rows(numRows);

    rows[0].resize(1);
    rows[0][0] = 1;

    for (int i{1}; i < numRows; ++i) {
      rows[i].resize(i + 1);
      rows[i][0] = rows[i][i] = 1;

      for (int j{1}; j < i; ++j) {
        rows[i][j] = rows[i - 1][j - 1] + rows[i - 1][j];
      }
    }

    return rows;
  }
};
