#include <algorithm>
#include <cstdlib>
#include <vector>

class Solution {
 public:
  int minTimeToVisitAllPoints(std::vector<std::vector<int>>& points) {
    int time = 0;

    // Calculate the distance between each pair of points.
    for (std::size_t i = 1; i < points.size(); ++i) {
      // The distance between two points is equal to the maximum distance between x and y axes.
      time += std::max(
          std::abs(points[i][0] - points[i - 1][0]),
          std::abs(points[i][1] - points[i - 1][1]));
    }

    return time;
  }
};
