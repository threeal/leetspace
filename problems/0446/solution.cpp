#include <unordered_map>
#include <vector>

class Solution {
 public:
  int numberOfArithmeticSlices(std::vector<int>& nums) {
    int total = 0;

    std::vector<std::unordered_map<int, int>> dp(nums.size());
    for (std::size_t j = 1; j < nums.size(); ++j) {
      for (std::size_t i = 0; i < j; ++i) {
        const int diff = nums[j] - nums[i];
        dp[j][diff] += 1;

        const auto it = dp[i].find(diff);
        if (it != dp[i].end()) {
          dp[j][diff] += dp[i][diff];
          total += dp[i][diff];
        }
      }
    }

    return total;
  }
};
