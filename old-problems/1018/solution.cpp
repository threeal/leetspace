#include <vector>

class Solution {
 public:
  std::vector<bool> prefixesDivBy5(std::vector<int>& nums) {
    std::vector<bool> output(nums.size());

    int ans{0};
    for (std::size_t i{0}; i < nums.size(); ++i) {
      ans = ((ans << 1) + nums[i]) % 5;
      output[i] = ans == 0;
    }

    return output;
  }
};
