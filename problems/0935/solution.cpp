#include <array>

const unsigned int mod = 1'000'000'007;

class Solution {
 public:
  int knightDialer(int n) {
    if (n == 1) return 10;

    std::array<unsigned int, 10> nums = {2, 2, 2, 2, 3, 0, 3, 2, 2, 2};

    while (--n > 1) {
      nums = {
          (nums[4] + nums[6]) % mod,
          (nums[6] + nums[8]) % mod,
          (nums[7] + nums[9]) % mod,
          (nums[4] + nums[8]) % mod,
          (nums[0] + nums[3] + nums[9]) % mod,
          0,
          (nums[0] + nums[1] + nums[7]) % mod,
          (nums[2] + nums[6]) % mod,
          (nums[1] + nums[3]) % mod,
          (nums[2] + nums[4]) % mod};
    }

    unsigned int total = 0;
    for (unsigned int i = 0; i < 10; ++i) {
      total = (total + nums[i]) % mod;
    }

    return total;
  }
};
