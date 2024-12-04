#include <bit>

class Solution {
 public:
  int bitwiseComplement(int n) {
    if (n == 0) return 1;
    return ~n & (std::bit_ceil<unsigned int>(n) - 1);
  }
};
