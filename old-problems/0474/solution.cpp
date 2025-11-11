#include <string>
#include <vector>

class Solution {
 public:
  int findMaxForm(std::vector<std::string>& strs, int m, int n) {
    std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 0));
    for (const std::string& str : strs) {
      int zeros{0}, ones{0};
      for (const char c : str) {
        if (c == '0') {
          ++zeros;
        } else {
          ++ones;
        }
      }

      for (int i{m}; i >= zeros; --i) {
        for (int j{n}; j >= ones; --j) {
          if (1 + dp[i - zeros][j - ones] > dp[i][j]) {
            dp[i][j] = 1 + dp[i - zeros][j - ones];
          }
        }
      }
    }

    return dp[m][n];
  }
};
