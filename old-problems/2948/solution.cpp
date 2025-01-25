#include <algorithm>
#include <numeric>
#include <vector>

class Solution {
 public:
  std::vector<int> lexicographicallySmallestArray(
      std::vector<int>& nums, int limit) {
    std::vector<int> numsIdxs(nums.size());
    std::iota(numsIdxs.begin(), numsIdxs.end(), 0);
    std::sort(numsIdxs.begin(), numsIdxs.end(), [&nums](int a, int b) {
      return nums[a] < nums[b];
    });

    std::vector<int> outputIdxs = numsIdxs;

    std::size_t prev{0};
    for (std::size_t i{1}; i < numsIdxs.size(); ++i) {
      if (nums[numsIdxs[i]] - nums[numsIdxs[i - 1]] > limit) {
        std::sort(outputIdxs.begin() + prev, outputIdxs.begin() + i);
        prev = i;
      }
    }
    std::sort(outputIdxs.begin() + prev, outputIdxs.end());

    std::vector<int> output(nums.size());
    for (std::size_t i{0}; i < nums.size(); ++i) {
      output[outputIdxs[i]] = nums[numsIdxs[i]];
    }

    return output;
  }
};
