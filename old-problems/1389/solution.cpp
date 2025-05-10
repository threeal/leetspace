#include <vector>

class Solution {
 public:
  std::vector<int> createTargetArray(
      std::vector<int>& nums, std::vector<int>& index) {
    std::vector<int> output{};
    output.reserve(nums.size());

    for (std::size_t i{0}; i < nums.size(); ++i) {
      output.insert(output.begin() + index[i], nums[i]);
    }

    return output;
  }
};
