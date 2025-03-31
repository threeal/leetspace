#include <cstdint>

class Solution {
 public:
  std::uint32_t reverseBits(std::uint32_t n) {
    std::uint32_t out{0};
    for (int i{0}; i < 32; ++i) {
      if ((n & (1 << i)) != 0) out |= 1 << (31 - i);
    }
    return out;
  }
};
