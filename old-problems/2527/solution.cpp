#include <vector>

class Solution {
 public:
  int xorBeauty(std::vector<int>& nums) {
    int ans{0};
    for (int num : nums) ans ^= num;
    return ans;
  }
};
