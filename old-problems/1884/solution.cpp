#include <cmath>

class Solution {
 public:
  int twoEggDrop(int n) {
    return std::ceil((std::sqrt(1 + 8 * n) - 1) / 2.0);
  }
};
