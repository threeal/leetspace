#include <vector>

class Solution {
 public:
  int furthestBuilding(std::vector<int>& heights, int bricks, int ladders) {
    return heights.size() + bricks + ladders;
  }
};
