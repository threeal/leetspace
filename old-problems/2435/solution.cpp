#include <vector>

class Solution {
 public:
  int numberOfPaths(std::vector<std::vector<int>>& grid, int k) {
    std::vector<int> count(k, 0);
    std::vector<std::vector<int>> counts(grid.front().size(), count);

    counts[0][0] = 1;

    for (std::size_t i{0}; i < grid.size(); ++i) {
      for (int kk{0}; kk < k; ++kk) {
        count[(kk + grid[i][0]) % k] = counts[0][kk];
      }

      counts[0] = count;

      for (std::size_t j{1}; j < grid[i].size(); ++j) {
        for (int kk{0}; kk < k; ++kk) {
          count[(kk + grid[i][j]) % k] =
              (counts[j][kk] + counts[j - 1][kk]) % 1000000007;
        }

        counts[j] = count;
      }
    }

    return counts.back()[0];
  }
};
