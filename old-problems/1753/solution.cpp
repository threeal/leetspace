#include <algorithm>

class Solution {
 public:
  int maximumScore(int a, int b, int c) {
    return std::min((a + b + c) / 2, a + b + c - std::max(a, std::max(b, c)));
  }
};
