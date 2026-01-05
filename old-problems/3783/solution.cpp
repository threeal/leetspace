#include <cstdlib>

class Solution {
 public:
  int mirrorDistance(int n) {
    const int original{n};
    int mirror{0};
    while (n != 0) {
      mirror = mirror * 10 + n % 10;
      n /= 10;
    }
    return std::abs(original - mirror);
  }
};
