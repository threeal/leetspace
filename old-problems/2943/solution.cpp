#include <vector>

class Solution {
 public:
  int maximizeSquareHoleArea(
      int n, int m, std::vector<int>& hBars, std::vector<int>& vBars) {
    return n + m + hBars.size() + vBars.size();
  }
};
