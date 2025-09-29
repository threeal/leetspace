#include <limits>
#include <vector>

class Solution {
 public:
  int minScoreTriangulation(std::vector<int>& values) {
    std::vector<std::vector<int>> dp(values.size() - 2);
    for (std::size_t i{0}; i < dp.size(); ++i) {
      dp[i].resize(values.size() - i - 2);
      for (std::size_t j{0}; j < dp[i].size(); ++j) {
        int minScore{std::numeric_limits<int>::max()};
        for (std::size_t k{0}; k <= i; ++k) {
          int score{values[j] * values[j + k + 1] * values[j + i + 2]};
          if (k > 0) score += dp[k - 1][j];
          if (k < i) score += dp[i - k - 1][j + k + 1];
          if (score < minScore) minScore = score;
        }
        dp[i][j] = minScore;
      }
    }
    return dp.back().back();
  }
};
