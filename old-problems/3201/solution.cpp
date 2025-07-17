#include <vector>

class Solution {
 public:
  int maximumLength(std::vector<int>& nums) {
    int dp[2][2]{{0, 0}, {0, 0}}, max{0};
    for (int num : nums) {
      num %= 2;

      dp[num][0] = dp[0][num] + 1;
      if (dp[num][0] > max) max = dp[num][0];

      dp[num][1] = dp[1][num] + 1;
      if (dp[num][1] > max) max = dp[num][1];
    }
    return max;
  }
};
