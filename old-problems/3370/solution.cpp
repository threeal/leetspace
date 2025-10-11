#include <bit>

class Solution {
 public:
  int smallestNumber(int n) {
    return (std::bit_floor<unsigned int>(n) << 1) - 1;
  }
};
