#include <numeric>
#include <utility>
#include <vector>

class Solution {
 public:
  bool canPartition(std::vector<int>& nums) {
    int sum{std::accumulate(nums.begin(), nums.end(), 0)};
    if (sum % 2 == 1) return false;
    sum /= 2;

    std::vector<bool> prev(sum + 1);
    prev[0] = true;

    std::vector<bool> curr(sum + 1);
    curr[0] = true;

    for (std::size_t i{1}; i < nums.size(); ++i) {
      std::swap(prev, curr);
      for (int k{1}; k <= sum; ++k) {
        curr[k] = prev[k] || (nums[i] <= k ? prev[k - nums[i]] : false);
      }
    }

    return curr[sum];
  }
};
