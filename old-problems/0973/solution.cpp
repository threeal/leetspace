#include <algorithm>
#include <vector>

class Solution {
 public:
  std::vector<std::vector<int>> kClosest(
      std::vector<std::vector<int>>& points, int k) {
    std::partial_sort(
        points.begin(), points.begin() + k, points.end(),
        [](const auto& a, const auto& b) {
          return (a[0] * a[0] + a[1] * a[1]) < (b[0] * b[0] + b[1] * b[1]);
        });

    points.resize(k);
    return points;
  }
};
