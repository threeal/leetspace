#include <cmath>
#include <limits>
#include <vector>

class Solution {
 public:
  std::vector<std::vector<int>> outerTrees(
      std::vector<std::vector<int>>& trees) {
    std::size_t br{0};
    for (std::size_t i{trees.size() - 1}; i > 0; --i) {
      if (trees[i][1] < trees[br][1] ||
          (trees[i][1] == trees[br][1] && trees[i][0] > trees[br][0])) {
        br = i;
      }
    }
    std::swap(trees[0], trees[br]);

    std::size_t next{0};
    std::size_t prev{0};
    double maxAngle{0.0};
    double prevAngle{std::numeric_limits<double>::infinity()};
    double minDistance{std::numeric_limits<double>::infinity()};
    while (prev < trees.size()) {
      for (std::size_t i{trees.size() - 1}; i > prev; --i) {
        const double x = trees[i][0] - trees[prev][0];
        const double y = trees[i][1] - trees[prev][1];
        const double angle{std::atan2(y, x)};
        if (angle > prevAngle) continue;
        const double distance{std::hypot(x, y)};
        if (angle > maxAngle || (angle == maxAngle && distance <= minDistance)) {
          next = i;
          maxAngle = angle;
          minDistance = distance;
        }
      }

      if (next == 0) {
        trees.resize(prev + 1);
        return trees;
      }

      ++prev;
      std::swap(trees[prev], trees[next]);
      prevAngle = maxAngle;

      next = 0;
      const double x = trees[next][0] - trees[prev][0];
      const double y = trees[next][1] - trees[prev][1];
      maxAngle = std::atan2(y, x);
      minDistance = std::hypot(x, y);
    }

    return trees;
  }
};
