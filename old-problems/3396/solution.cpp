#include <vector>

class Solution {
 public:
  int minimumOperations(std::vector<int>& nums) {
    std::vector<bool> exists(101, false);

    std::size_t l{0};
    for (std::size_t i{0}; i < nums.size(); ++i) {
      while (i >= l + 3 && exists[nums[i]]) {
        exists[nums[l++]] = false;
        exists[nums[l++]] = false;
        exists[nums[l++]] = false;
      }

      if (exists[nums[i]]) {
        for (std::size_t j{l}; j < i; ++j) exists[nums[j]] = false;
        i = l + 2;
        l += 3;
      } else {
        exists[nums[i]] = true;
      }
    }

    return l / 3;
  }
};
