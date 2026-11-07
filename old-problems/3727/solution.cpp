#include <algorithm>
#include <vector>

class Solution {
 public:
  long long maxAlternatingSum(std::vector<int>& nums) {
    for (std::size_t i{0}; i < nums.size(); ++i) {
      nums[i] *= nums[i];
    }

    std::sort(nums.begin(), nums.end());

    long long sum{0};

    const std::size_t half{nums.size() / 2};
    for (std::size_t i{0}; i < half; ++i) {
      sum -= nums[i];
    }

    for (std::size_t i{half}; i < nums.size(); ++i) {
      sum += nums[i];
    }

    return sum;
  }
};
