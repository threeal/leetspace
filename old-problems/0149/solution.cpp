#include <numeric>
#include <unordered_map>
#include <vector>

class Solution {
 public:
  int maxPoints(std::vector<std::vector<int>>& points) {
    std::unordered_map<int, std::unordered_map<int, std::unordered_map<int, int>>> counts{};

    for (std::size_t i{0}; i < points.size(); ++i) {
      for (std::size_t j{i + 1}; j < points.size(); ++j) {
        int dy = points[j][0] - points[i][0];
        int dx = points[j][1] - points[i][1];

        const int gcd = std::gcd(dy, dx);
        dy /= gcd;
        dx /= gcd;
        if (dy <= 0 && (dy < 0 || dx < 0)) {
          dy = -dy;
          dx = -dx;
        }

        const int c = points[i][0] * dx - points[i][1] * dy;
        ++counts[dy][dx][c];
      }
    }

    int maxCount{0};
    for (const auto& [dy, counts] : counts) {
      for (const auto& [dx, counts] : counts) {
        for (const auto& [c, count] : counts) {
          if (count > maxCount) maxCount = count;
        }
      }
    }

    int low{0}, high{maxCount};
    while (low < high) {
      const int mid = low + (high - low) / 2;
      if ((mid * (mid + 1)) / 2 < maxCount) {
        low = mid + 1;
      } else {
        high = mid;
      }
    }
    return low + 1;
  }
};
