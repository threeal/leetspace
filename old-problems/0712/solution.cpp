#include <string>
#include <vector>

class Solution {
 public:
  int minimumDeleteSum(std::string s1, std::string s2) {
    std::vector<int> dp(s2.size() + 1, 0);

    for (std::size_t i{0}; i < s1.size(); ++i) {
      int prevTl{0};
      for (std::size_t j{0}; j < s2.size(); ++j) {
        if (s1[i] == s2[j]) {
          const int tempPrevTl{prevTl};
          prevTl = dp[j + 1];
          dp[j + 1] = tempPrevTl + s1[i];
        } else {
          prevTl = dp[j + 1];
          if (dp[j] > dp[j + 1]) dp[j + 1] = dp[j];
        }
      }
    }

    int sum{0};
    for (char c : s1) sum += c;
    for (char c : s2) sum += c;

    return sum - 2 * dp[s2.size()];
  }
};
