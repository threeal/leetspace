#include <vector>

class Solution {
 public:
  int findKOr(std::vector<int>& nums, int k) {
    int freqs[32]{0};
    for (int num : nums) {
      for (int i{0}; num != 0; ++i) {
        if ((num & 1) != 0) ++freqs[i];
        num >>= 1;
      }
    }

    int num{0};
    for (int i{0}; i < 32; ++i) {
      if (freqs[i] >= k) num |= 1 << i;
    }

    return num;
  }
};
