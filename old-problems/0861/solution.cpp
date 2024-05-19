#include <vector>

class Solution {
 public:
  int matrixScore(std::vector<std::vector<int>>& grid) {
    for (auto& row : grid) {
      if (row[0] == 1) continue;
      for (auto& val : row) val = val == 0 ? 1 : 0;
    }

    const int m = grid.size();
    const int n = grid.front().size();
    for (int j{0}; j < n; ++j) {
      int ones{0};
      for (int i{0}; i < m; ++i) {
        if (grid[i][j] == 1) ++ones;
      }

      if (ones < m - ones) {
        for (int i{0}; i < m; ++i) {
          grid[i][j] = grid[i][j] == 0 ? 1 : 0;
        }
      }
    }

    int totalScore{0};
    for (auto& row : grid) {
      int score{0};
      for (int j{0}; j < n; ++j) {
        if (row[j] == 1) score |= 1 << (n - j - 1);
      }
      totalScore += score;
    }

    return totalScore;
  }
};
