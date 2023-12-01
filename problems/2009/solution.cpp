#include <algorithm>
#include <limits>
#include <vector>

class Solution {
 public:
  int minOperations(std::vector<int>& nums) {
    const int n = nums.size();
    std::sort(nums.begin(), nums.end());

    const auto unique_nums = std::vector(nums.begin(), std::unique(nums.begin(), nums.end()));
    const int unique_n = unique_nums.size();

    int res = std::numeric_limits<int>::max();
    for (int a = 0; a < unique_n; ++a) {
      const int b_val = unique_nums[a] + n - 1;
      const auto it = std::upper_bound(unique_nums.begin(), unique_nums.end(), b_val);
      const int b = std::distance(unique_nums.begin(), it);
      res = std::min(res, n - (b - a));
    }

    return res;
  }
};
