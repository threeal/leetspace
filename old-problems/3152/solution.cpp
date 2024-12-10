#include <vector>

class Solution {
 public:
  std::vector<bool> isArraySpecial(
      std::vector<int>& nums, std::vector<std::vector<int>>& queries) {
    int group{0};
    int mod{nums[0] % 2};
    nums[0] = group;
    for (std::size_t i{1}; i < nums.size(); ++i) {
      if (nums[i] % 2 == mod) ++group;
      mod = nums[i] % 2;
      nums[i] = group;
    }

    std::vector<bool> outputs{};
    outputs.reserve(queries.size());
    for (const auto& query : queries) {
      outputs.push_back(nums[query[0]] == nums[query[1]]);
    }

    return outputs;
  }
};
