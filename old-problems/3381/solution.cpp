#include <vector>

class Solution {
 public:
  long long maxSubarraySum(std::vector<int>& nums, int k) {
    long long sum{0};
    for (int i{0}; i < k; ++i) sum += nums[i];

    std::vector<long long> prefixes(nums.size(), 0);

    prefixes[k - 1] = sum;
    long long maxSum{sum};

    for (std::size_t i = k; i < nums.size(); ++i) {
      sum += nums[i] - nums[i - k];

      prefixes[i] = prefixes[i - k] > 0 ? sum + prefixes[i - k] : sum;
      if (prefixes[i] > maxSum) maxSum = prefixes[i];
    }

    return maxSum;
  }
};
