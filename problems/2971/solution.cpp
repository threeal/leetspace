#include <algorithm>
#include <numeric>
#include <vector>

class Solution {
 public:
  long long largestPerimeter(std::vector<int>& nums) {
    std::sort(nums.begin(), nums.end());
    auto sum = std::accumulate(nums.begin(), nums.end(), 0ll, std::plus<long long>());

    for (std::size_t i = nums.size() - 1; i >= 2; --i) {
      sum -= nums[i];
      if (sum > nums[i]) {
        return sum + nums[i];
      }
    }

    return -1;
  }
};
