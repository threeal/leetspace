#include <string>
#include <vector>

class Solution {
 public:
  int minInsertions(std::string s) {
    std::vector<int> dp(s.size() + 1, 0);
    for (std::size_t i{0}; i < s.size(); ++i) {
      int prev{dp[0]};
      for (std::size_t j{0}; j < s.size(); ++j) {
        const int temp{dp[j + 1]};
        if (s[i] == s[s.size() - j - 1]) {
          dp[j + 1] = prev + 1;
        } else {
          if (dp[j] > dp[j + 1]) dp[j + 1] = dp[j];
        }
        prev = temp;
      }
    }
    return s.size() - dp[s.size()];
  }
};
