#include <vector>

class Solution {
 public:
  int rangeSum(
      std::vector<int>& nums, int n, int left, int right) {
    std::vector<int> sums((n * (n + 1)) / 2);
    auto it = sums.begin();

    for (std::size_t i{0}; i < nums.size(); ++i) {
      for (std::size_t j{0}; j < i; ++j) {
        nums[j] += nums[i];
        *it = nums[j];
        ++it;
      }

      *it = nums[i];
      ++it;
    }

    std::sort(sums.begin(), sums.end());

    int sum{0};
    for (int i{left - 1}; i < right; ++i) {
      sum = (sum + sums[i]) % 1000000007;
    }

    return sum;
  }
};
