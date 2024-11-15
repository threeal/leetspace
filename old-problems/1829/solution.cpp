#include <vector>

class Solution {
 public:
  std::vector<int> getMaximumXor(std::vector<int>& nums, int maximumBit) {
    std::vector<int> output(nums.size());

    int max = (1 << maximumBit) - 1;
    int ans{0};
    for (std::size_t i{0}; i < nums.size(); ++i) {
      ans ^= nums[i];
      output[output.size() - i - 1] = max ^ ans;
    }

    return output;
  }
};
