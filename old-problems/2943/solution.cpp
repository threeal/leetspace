#include <algorithm>
#include <vector>

class Solution {
 public:
  int maximizeSquareHoleArea(
      int n, int m, std::vector<int>& hBars, std::vector<int>& vBars) {
    (void)n;
    (void)m;

    std::sort(hBars.begin(), hBars.end());
    std::sort(vBars.begin(), vBars.end());

    int hMaxCount{1}, hCount{1};
    for (std::size_t i{1}; i < hBars.size(); ++i) {
      if (hBars[i] == hBars[i - 1] + 1) {
        if (++hCount > hMaxCount) hMaxCount = hCount;
      } else {
        hCount = 1;
      }
    }

    int vMaxCount{1}, vCount{1};
    for (std::size_t i{1}; i < vBars.size(); ++i) {
      if (vBars[i] == vBars[i - 1] + 1) {
        if (++vCount > vMaxCount) vMaxCount = vCount;
      } else {
        vCount = 1;
      }
    }

    int maxCount{1 + (hMaxCount <= vMaxCount ? hMaxCount : vMaxCount)};
    return maxCount * maxCount;
  }
};
