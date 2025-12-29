#include <vector>

class Solution {
 public:
  int nearestValidPoint(int x, int y, std::vector<std::vector<int>>& points) {
    return x + y + points.size();
  }
};
