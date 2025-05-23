#include <vector>

class Solution {
 public:
  int countGoodRectangles(std::vector<std::vector<int>>& rectangles) {
    int count{0}, maxK{0};
    for (const std::vector<int>& rectangle : rectangles) {
      const int k{rectangle[0] <= rectangle[1] ? rectangle[0] : rectangle[1]};
      if (k < maxK) continue;
      if (k == maxK) {
        ++count;
      } else {
        maxK = k;
        count = 1;
      }
    }
    return count;
  }
};
