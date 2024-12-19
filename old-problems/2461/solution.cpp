#include <unordered_map>
#include <vector>

class Solution {
 public:
  long long maximumSubarraySum(std::vector<int>& nums, int k) {
    long long maxSum{0}, sum{0};
    std::unordered_map<int, int> freqs{};

    for (int i{0}; i < k; ++i) {
      sum += nums[i];
      const auto it = freqs.find(nums[i]);
      if (it == freqs.end()) {
        freqs.emplace(nums[i], 1);
      } else {
        ++(it->second);
      }
    }

    if (static_cast<int>(freqs.size()) == k) maxSum = sum;

    for (std::size_t i = k; i < nums.size(); ++i) {
      sum += nums[i] - nums[i - k];

      if (nums[i] != nums[i - k]) {
        const auto prev = freqs.find(nums[i - k]);
        --(prev->second);
        if (prev->second == 0) {
          freqs.erase(prev);
        }

        const auto next = freqs.find(nums[i]);
        if (next == freqs.end()) {
          freqs.emplace(nums[i], 1);
        } else {
          ++(next->second);
        }
      }

      if (static_cast<int>(freqs.size()) == k && sum > maxSum) maxSum = sum;
    }

    return maxSum;
  }
};
