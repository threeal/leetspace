#include <numeric>
#include <vector>

class Solution {
 public:
  int minSubarray(std::vector<int>& nums, int p) {
    const auto mod = std::accumulate(nums.begin(), nums.end(), 0ll) % p;
    if (mod == 0) return 0;

    for (std::size_t n{1}; n < nums.size(); ++n) {
      auto sum = std::accumulate(nums.begin(), nums.begin() + n, 0ll);
      if (sum % p == mod) return n;

      for (std::size_t i{n}; i < nums.size(); ++i) {
        sum = sum + nums[i] - nums[i - n];
        if (sum % p == mod) return n;
      }
    }

    return -1;
  }
};
