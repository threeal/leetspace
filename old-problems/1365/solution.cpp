#include <algorithm>
#include <numeric>
#include <vector>

class Solution {
 public:
  std::vector<int> smallerNumbersThanCurrent(std::vector<int>& nums) {
    std::vector<std::size_t> indices(nums.size());
    std::iota(indices.begin(), indices.end(), 0);

    std::sort(
        indices.begin(), indices.end(),
        [&](std::size_t a, std::size_t b) {
          return nums[a] < nums[b];
        });

    std::vector<int> output(nums.size());
    output[indices[0]] = 0;

    for (std::size_t i{1}; i < indices.size(); ++i) {
      if (nums[indices[i]] == nums[indices[i - 1]]) {
        output[indices[i]] = output[indices[i - 1]];
      } else {
        output[indices[i]] = i;
      }
    }

    return output;
  }
};
