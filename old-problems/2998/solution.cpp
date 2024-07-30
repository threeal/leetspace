#include <algorithm>

class Solution {
 public:
  int minimumOperationsToMakeEqual(int x, int y) {
    if (x <= y) return y - x;
    const int eleven = x % 11 <= 5
        ? x % 11 + minimumOperationsToMakeEqual(x / 11, y)
        : 11 - x % 11 + minimumOperationsToMakeEqual(x / 11 + 1, y);
    const int five = x % 5 <= 2
        ? x % 5 + minimumOperationsToMakeEqual(x / 5, y)
        : 5 - x % 5 + minimumOperationsToMakeEqual(x / 5 + 1, y);
    return std::min(x - y, 1 + std::min(eleven, five));
  }
};
