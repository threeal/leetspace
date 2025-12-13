#include <bit>

class Solution {
 public:
  int minFlips(int a, int b, int c) {
    c ^= a | b;
    return std::popcount<unsigned int>(c) +
        std::popcount<unsigned int>(a & b & c);
  }
};
