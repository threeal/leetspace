#include <limits>
#include <unordered_map>
#include <vector>

class Solution {
 public:
  int numberOfArithmeticSlices(std::vector<int>& nums) {
    int total = 0;

    std::vector<std::unordered_map<int, int>> dp(nums.size());
    for (std::size_t j = 1; j < nums.size(); ++j) {
      for (std::size_t i = 0; i < j; ++i) {
        const auto diff = static_cast<long long>(nums[j]) - static_cast<long long>(nums[i]);
        if (diff < std::numeric_limits<int>::min() || diff > std::numeric_limits<int>::max()) {
          continue;
        }

        dp[j][static_cast<int>(diff)] += 1;

        const auto it = dp[i].find(static_cast<int>(diff));
        if (it != dp[i].end()) {
          dp[j][static_cast<int>(diff)] += dp[i][static_cast<int>(diff)];
          total += dp[i][static_cast<int>(diff)];
        }
      }
    }

    return total;
  }
};
