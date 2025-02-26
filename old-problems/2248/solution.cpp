#include <algorithm>
#include <vector>

class Solution {
 public:
  std::vector<int> intersection(std::vector<std::vector<int>>& nums) {
    std::size_t freqs[10001] = {0};
    for (std::size_t i{nums.size() - 1}; i > 0; --i) {
      for (const auto num : nums[i]) ++freqs[num];
    }

    std::vector<int> output{};
    for (const auto num : nums[0]) {
      if (++freqs[num] == nums.size()) output.push_back(num);
    }

    std::sort(output.begin(), output.end());
    return output;
  }
};
