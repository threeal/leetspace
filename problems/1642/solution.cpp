#include <queue>
#include <vector>

class Solution {
 public:
  int furthestBuilding(std::vector<int>& heights, int bricks, int ladders) {
    std::priority_queue<int, std::vector<int>, std::greater<>> pq;

    for (std::size_t i = 1; i < heights.size(); ++i) {
      const auto diff = heights[i] - heights[i - 1];
      if (diff <= 0) continue;

      pq.push(diff);
      if (pq.size() <= static_cast<std::size_t>(ladders)) continue;

      bricks -= pq.top();
      pq.pop();
      if (bricks < 0) return i - 1;
    }

    return heights.size() - 1;
  }
};
