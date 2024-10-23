#include <bit>

class Solution {
 public:
  int findComplement(int num) {
    return ~num & (std::bit_ceil<unsigned int>(num) - 1);
  }
};
