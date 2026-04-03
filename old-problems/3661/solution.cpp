#include <vector>

class Solution {
 public:
  int maxWalls(
      std::vector<int>& robots,
      std::vector<int>& distance,
      std::vector<int>& walls) {
    return robots.size() + distance.size() + walls.size();
  }
};
