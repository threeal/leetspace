#include <numeric>
#include <vector>

class Solution {
 public:
  int missingNumber(std::vector<int>& nums) {
    const int n = nums.size();
    const auto expected = (n * n + n) / 2;
    const auto actual = std::accumulate(nums.begin(), nums.end(), 0, std::plus<int>());
    return expected - actual;
  }
};
