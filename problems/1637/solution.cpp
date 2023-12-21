#include <algorithm>
#include <vector>

class Solution {
 public:
  int maxWidthOfVerticalArea(std::vector<std::vector<int>>& points) {
    std::vector<int> xs(points.size());
    for (std::size_t i = 0; i < points.size(); ++i) {
      xs[i] = points[i][0];
    }

    std::sort(xs.begin(), xs.end());

    int prev_x = xs[0];
    int max_width = 0;
    for (std::size_t i = 1; i < xs.size(); ++i) {
      if (xs[i] == prev_x) continue;
      max_width = std::max(max_width, xs[i] - prev_x);
      prev_x = xs[i];
    }

    return max_width;
  }
};
