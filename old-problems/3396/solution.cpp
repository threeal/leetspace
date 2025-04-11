#include <vector>

class Solution {
 public:
  int minimumOperations(std::vector<int>& nums) {
    std::vector<std::size_t> indices(101, 0);

    std::size_t i{0};
    for (std::size_t j{0}; j < nums.size(); ++j) {
      if (indices[nums[j]] > i) i = indices[nums[j]];
      indices[nums[j]] = j + 1;
    }

    return i % 3 == 0 ? i / 3 : i / 3 + 1;
  }
};
