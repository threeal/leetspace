#include <vector>

class Solution {
 public:
  std::vector<int> maxSumOfThreeSubarrays(
      std::vector<int>& nums, int k) {
    int sum{0};
    for (int i{1}; i < k; ++i) sum += nums[i];

    nums[0] += sum;
    for (std::size_t i = k; i < nums.size(); ++i) {
      sum += nums[i];
      sum -= nums[i + 1 - k];
      nums[i + 1 - k] += sum;
    }

    std::vector<std::size_t> indexes(nums.size() - k);
    std::size_t maxIndex{nums.size() - 1};
    for (int i = indexes.size() - 1; i >= 0; --i) {
      indexes[i] = maxIndex;
      if (nums[i + k - 1] >= nums[maxIndex]) maxIndex = i + k - 1;
    }

    maxIndex = indexes.size() - 1;
    int maxSum{nums[maxIndex] + nums[indexes[maxIndex]]};

    int a = maxIndex - k, b = maxIndex, c = indexes[maxIndex];
    for (int i = a - 1; i >= 0; --i) {
      const int sum{nums[i + k] + nums[indexes[i + k]]};
      if (sum >= maxSum) {
        maxIndex = i + k;
        maxSum = sum;
      }

      if (nums[i] + maxSum >= nums[a] + nums[b] + nums[c]) {
        a = i;
        b = maxIndex;
        c = indexes[maxIndex];
      }
    }

    return {a, b, c};
  }
};
