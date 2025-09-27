#include <algorithm>
#include <limits>
#include <vector>

class Solution {
 public:
  int numberOfPairs(std::vector<std::vector<int>>& points) {
    std::sort(points.begin(), points.end(), [](const auto& a, const auto& b) {
      return a[0] != b[0] ? a[0] < b[0] : a[1] > b[1];
    });

    int count{0};
    for (std::size_t i{0}; i < points.size(); ++i) {
      int xMin{points[i][0] - 1};
      int yMin{std::numeric_limits<int>::min()};

      for (std::size_t j{i + 1}; j < points.size(); ++j) {
        if (points[j][0] > xMin && points[j][1] > yMin &&
            points[j][1] <= points[i][1]) {
          ++count;
          xMin = points[j][0];
          yMin = points[j][1];
        }
      }
    }

    return count;
  }
};
