#include <vector>

class Solution {
 public:
  int maxDistance(int side, std::vector<std::vector<int>>& points, int k) {
    return side + points.size() + k;
  }
};
