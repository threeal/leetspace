#include <algorithm>
#include <vector>

class Solution {
 private:
  static int dfs(
      std::vector<std::vector<int>>& grid,
      std::vector<std::vector<std::vector<int>>>& dp,
      std::size_t i, std::size_t j, int sum) {
    sum ^= grid[i][j];
    if (dp[i][j][sum] == -1) {
      if (i + 1 < grid.size()) {
        dp[i][j][sum] = j + 1 < grid[i].size()
            ? std::min(dfs(grid, dp, i + 1, j, sum), dfs(grid, dp, i, j + 1, sum))
            : dfs(grid, dp, i + 1, j, sum);
      } else {
        dp[i][j][sum] = j + 1 < grid[i].size()
            ? dfs(grid, dp, i, j + 1, sum)
            : dp[i][j][sum] = sum;
      }
    }

    return dp[i][j][sum];
  }

 public:
  int minCost(std::vector<std::vector<int>>& grid) {
    std::vector<std::vector<std::vector<int>>> dp(
        grid.size(),
        std::vector<std::vector<int>>(
            grid[0].size(), std::vector<int>(1024, -1)));

    return dfs(grid, dp, 0, 0, 0);
  }
};
