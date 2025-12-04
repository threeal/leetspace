#include <vector>

class Solution {
 public:
  std::vector<int> evenOddBit(int n) {
    int evens{0}, odds{0};
    for (int i{1}; i <= n; i <<= 1) {
      if ((n & i) != 0) ++evens;
      if ((i <<= 1) > n) break;
      if ((n & i) != 0) ++odds;
    }
    return {evens, odds};
  }
};
