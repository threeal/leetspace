#include <bit>

class Solution {
 public:
  int hammingDistance(int x, int y) {
    return std::popcount<unsigned int>(x ^ y);
  }
};
