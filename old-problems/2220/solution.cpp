#include <bit>

class Solution {
 public:
  int minBitFlips(int start, int goal) {
    return std::popcount<unsigned int>(start ^ goal);
  }
};
