#include <algorithm>
#include <bit>
#include <vector>

class Solution {
 public:
  int maxGoodNumber(std::vector<int>& nums) {
    const int a{nums[0]}, an{32 - std::countl_zero<unsigned int>(a)};
    const int b{nums[1]}, bn{32 - std::countl_zero<unsigned int>(b)};
    const int c{nums[2]}, cn{32 - std::countl_zero<unsigned int>(c)};
    return std::max(
        std::max(
            a << (bn + cn) | std::max(b << cn | c, c << bn | b),
            b << (an + cn) | std::max(a << cn | c, c << an | a)),
        c << (an + bn) | std::max(a << bn | b, b << an | a));
  }
};
