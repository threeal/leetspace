#include <algorithm>
#include <numeric>
#include <vector>

class Solution {
 public:
  std::vector<int> minSubsequence(std::vector<int>& nums) {
    std::sort(nums.begin(), nums.end(), std::greater<int>());

    std::size_t n{0};
    int sum{0}, restSum{std::accumulate(nums.begin(), nums.end(), 0)};
    while (sum <= restSum) {
      sum += nums[n];
      restSum -= nums[n];
      ++n;
    }

    nums.resize(n);
    return nums;
  }
};
