#include <bit>

class Solution {
 public:
  int binaryGap(int n) {
    unsigned int nn = n;
    nn >>= std::countr_zero(nn) + 1;

    int maxGap{0};
    while (nn != 0) {
      const int gap{std::countr_zero(nn) + 1};
      if (gap >= maxGap) maxGap = gap;
      nn >>= gap;
    }

    return maxGap;
  }
};
