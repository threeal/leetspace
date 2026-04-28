#include <algorithm>
#include <numeric>
#include <vector>

class Solution {
 public:
  int minimumDistance(std::vector<int>& nums) {
    std::vector<std::size_t> idxs(nums.size());
    std::iota(idxs.begin(), idxs.end(), 0);

    std::sort(
        idxs.begin(), idxs.end(), [&nums](std::size_t a, std::size_t b) {
          return nums[a] == nums[b] ? a < b : nums[a] < nums[b];
        });

    std::size_t minDist{nums.size()};
    for (std::size_t i{2}; i < idxs.size(); ++i) {
      if (nums[idxs[i - 2]] == nums[idxs[i]] &&
          idxs[i] - idxs[i - 2] < minDist) {
        minDist = idxs[i] - idxs[i - 2];
      }
    }

    return minDist == nums.size() ? -1 : minDist * 2;
  }
};
