#include <algorithm>
#include <numeric>
#include <vector>

class Solution {
 public:
  std::vector<int> getFinalState(
      std::vector<int>& nums, int k, int multiplier) {
    std::vector<std::size_t> idxs(nums.size());
    std::iota(idxs.begin(), idxs.end(), 0);

    auto end = idxs.end();
    while (k > 0) {
      const auto range = idxs.begin() + std::min<std::size_t>(k, idxs.size());
      std::partial_sort(
          idxs.begin(), range, end,
          [&nums](const std::size_t a, const std::size_t b) -> bool {
            return nums[a] == nums[b] ? a < b : nums[a] < nums[b];
          });

      nums[idxs.front()] *= multiplier;
      end = range;
      --k;
    }

    return nums;
  }
};
