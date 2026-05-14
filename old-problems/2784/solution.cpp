#include <vector>

class Solution {
 public:
  bool isGood(std::vector<int>& nums) {
    const int n = nums.size() - 1;
    std::vector<bool> exists(n + 1, false);
    int nCount{0};
    for (const int num : nums) {
      if (num > n) return false;
      if (num < n) {
        if (exists[num]) return false;
        exists[num] = true;
      } else {
        if (++nCount == 3) return false;
      }
    }
    return true;
  }
};
