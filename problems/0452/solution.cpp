#include <algorithm>
#include <vector>

class Solution {
 public:
  int findMinArrowShots(std::vector<std::vector<int>>& points) {
    std::sort(points.begin(), points.end(), [](const auto& a, const auto& b) {
      return a[0] < b[0];
    });

    int arrows = 1;
    int end = points[0][1];
    for (std::size_t i = 1; i < points.size(); ++i) {
      if (points[i][0] > end) {
        ++arrows;
        end = points[i][1];
      } else if (points[i][1] < end) {
        end = points[i][1];
      }
    }

    return arrows;
  }
};
