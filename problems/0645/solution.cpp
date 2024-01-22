#include <vector>

class Solution {
 public:
  std::vector<int> findErrorNums(std::vector<int>& nums) {
    int twice = 0;
    int missing = 0;

    const int n = nums.size();
    std::vector<bool> flags(n + 1, false);

    for (const auto num : nums) {
      if (flags[num])
        twice = num;
      else
        flags[num] = true;
    }

    for (int i = 1; i <= n; ++i) {
      if (!flags[i]) {
        missing = i;
        break;
      }
    }

    return {twice, missing};
  }
};
