#include <string>
#include <vector>

class Solution {
 public:
  bool isInterleave(std::string s1, std::string s2, std::string s3) {
    if (s1.size() + s2.size() != s3.size()) return false;

    std::vector<bool> dp(s2.size() + 1, false);
    dp[0] = true;

    for (std::size_t i{1}; i <= s2.size(); ++i) {
      dp[i] = dp[i - 1] && s2[i - 1] == s3[i - 1];
    }

    for (std::size_t i{1}; i <= s1.size(); ++i) {
      dp[0] = dp[0] && s1[i - 1] == s3[i - 1];
      for (std::size_t j{1}; j <= s2.size(); ++j) {
        dp[j] = (dp[j] && s1[i - 1] == s3[i + j - 1]) ||
            (dp[j - 1] && s2[j - 1] == s3[i + j - 1]);
      }
    }

    return dp[s2.size()];
  }
};
