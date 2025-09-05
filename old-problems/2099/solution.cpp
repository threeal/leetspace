#include <algorithm>
#include <numeric>
#include <vector>

class Solution {
 public:
  std::vector<int> maxSubsequence(std::vector<int>& nums, int k) {
    std::vector<int> indices(nums.size());
    std::iota(indices.begin(), indices.end(), 0);
    std::partial_sort(
        indices.begin(), indices.begin() + k, indices.end(),
        [&nums](int a, int b) {
          return nums[a] > nums[b];
        });

    indices.resize(k);
    std::sort(indices.begin(), indices.end());

    for (auto& index : indices) {
      index = nums[index];
    }

    return indices;
  }
};
