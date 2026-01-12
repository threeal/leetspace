#include <cstdlib>
#include <limits>
#include <vector>

class Solution {
 public:
  int nearestValidPoint(int x, int y, std::vector<std::vector<int>>& points) {
    int nearest{-1}, distance{std::numeric_limits<int>::max()};
    for (std::size_t i{0}; i < points.size(); ++i) {
      if (points[i][0] == x) {
        if (std::abs(points[i][1] - y) < distance) {
          nearest = i;
          distance = std::abs(points[i][1] - y);
        }
      } else if (points[i][1] == y) {
        if (std::abs(points[i][0] - x) < distance) {
          nearest = i;
          distance = std::abs(points[i][0] - x);
        }
      }
    }

    return nearest;
  }
};
