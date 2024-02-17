#include <queue>
#include <vector>

class Solution {
 public:
  int furthestBuilding(std::vector<int>& heights, int bricks, int ladders) {
    std::priority_queue<int> q;

    std::size_t i = 1;
    while (i < heights.size()) {
      const auto diff = heights[i] - heights[i - 1];
      if (diff > 0) {
        bricks -= diff;
        q.push(diff);

        while (bricks < 0) {
          bricks += q.top();
          q.pop();
          --ladders;
        }

        if (ladders < 0) break;
      }

      ++i;
    }

    return i - 1;
  }
};
