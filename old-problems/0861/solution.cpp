#include <algorithm>
#include <vector>

class Solution {
 public:
  int matrixScore(std::vector<std::vector<int>>& grid) {
    const int m = grid.size();
    const int n = grid.front().size();

    int score{(1 << (n - 1)) * m};
    for (int j{1}; j < n; ++j) {
      int count{0};
      for (int i{0}; i < m; ++i) {
        if (grid[i][j] == grid[i][0]) ++count;
      }
      score += (1 << (n - j - 1)) * std::max(count, m - count);
    }

    return score;
  }
};
