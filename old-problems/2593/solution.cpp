#include <algorithm>
#include <numeric>
#include <vector>

class Solution {
 public:
  long long findScore(std::vector<int>& nums) {
    std::vector<bool> marked(nums.size(), false);
    std::vector<std::size_t> idxs(nums.size());
    std::iota(idxs.begin(), idxs.end(), 0);

    std::sort(idxs.begin(), idxs.end(), [&nums](std::size_t a, std::size_t b) {
      return nums[a] == nums[b] ? a < b : nums[a] < nums[b];
    });

    long long score{0};
    for (const auto idx : idxs) {
      if (marked[idx]) continue;
      score += nums[idx];
      marked[idx] = true;
      if (idx > 0) marked[idx - 1] = true;
      if (idx < marked.size() - 1) marked[idx + 1] = true;
    }

    return score;
  }
};
