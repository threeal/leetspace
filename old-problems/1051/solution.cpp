#include <algorithm>
#include <vector>

class Solution {
 public:
  int heightChecker(std::vector<int>& heights) {
    std::vector<int> sortedHeights{heights};
    std::sort(sortedHeights.begin(), sortedHeights.end());

    int diff{0};
    for (int i = heights.size() - 1; i >= 0; --i) {
      if (heights[i] != sortedHeights[i]) ++diff;
    }

    return diff;
  }
};
