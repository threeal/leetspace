#include <cstdlib>
#include <functional>
#include <vector>

class Solution {
 public:
  int furthestBuilding(std::vector<int>& heights, int bricks, int ladders) {
    const int n = heights.size();
    const std::function<int(int, int, int)> fn = [&](int i, int bricks, int ladders) {
      if (i >= n) return i - 1;

      const auto diff = heights[i] - heights[i - 1];
      if (diff <= 0) {
        return fn(i + 1, bricks, ladders);
      }

      if (bricks >= diff) {
        if (ladders > 0) {
          return std::max(
              fn(i + 1, bricks - diff, ladders),
              fn(i + 1, bricks, ladders - 1));
        } else {
          return fn(i + 1, bricks - diff, ladders);
        }
      } else if (ladders > 0) {
        return fn(i + 1, bricks, ladders - 1);
      }

      return i - 1;
    };

    return fn(1, bricks, ladders);
  }
};
