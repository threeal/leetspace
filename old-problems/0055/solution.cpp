#include <vector>

class Solution {
 public:
  bool canJump(std::vector<int>& nums) {
    if (nums.size() <= 1) return true;
    nums.back() = 1;

    int maxJump{0};
    for (const auto num : nums) {
      --maxJump;
      if (num == 0) {
        if (maxJump <= 0) return false;
      } else {
        if (num > maxJump) maxJump = num;
      }
    }

    return true;
  }
};
