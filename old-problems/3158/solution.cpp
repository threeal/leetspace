#include <vector>

class Solution {
 public:
  int duplicateNumbersXOR(std::vector<int>& nums) {
    bool exists[51]{false};
    int ans{0};
    for (const auto num : nums) {
      if (exists[num]) {
        ans ^= num;
      } else {
        exists[num] = true;
      }
    }
    return ans;
  }
};
