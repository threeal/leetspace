#include <vector>

class Solution {
 public:
  int minOperations(std::vector<int>& nums, int k) {
    std::vector<bool> exists(101, false);
    int count{0};
    for (const auto num : nums) {
      if (num < k) return -1;
      if (!exists[num]) {
        exists[num] = true;
        ++count;
      }
    }
    if (exists[k]) --count;
    return count;
  }
};
