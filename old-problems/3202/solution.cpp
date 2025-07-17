#include <vector>

class Solution {
 public:
  int maximumLength(std::vector<int>& nums, int k) {
    std::vector<std::vector<int>> dp(k, std::vector(k, 0));
    int max{0};
    for (int num : nums) {
      num %= k;
      for (int prev{0}; prev < k; ++prev) {
        dp[num][prev] = dp[prev][num] + 1;
        if (dp[num][prev] > max) max = dp[num][prev];
      }
    }
    return max;
  }
};
