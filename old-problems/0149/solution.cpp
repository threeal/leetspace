#include <cstdint>
#include <numeric>
#include <unordered_map>
#include <vector>

class Solution {
 public:
  int maxPoints(std::vector<std::vector<int>>& points) {
    std::unordered_map<std::uint64_t, int> counts{};

    for (std::size_t i{0}; i < points.size(); ++i) {
      for (std::size_t j{i + 1}; j < points.size(); ++j) {
        std::int16_t dy = points[j][0] - points[i][0];
        std::int16_t dx = points[j][1] - points[i][1];

        const auto gcd = std::gcd(dy, dx);
        dy /= gcd;
        dx /= gcd;
        if (dy <= 0 && (dy < 0 || dx < 0)) {
          dy = -dy;
          dx = -dx;
        }

        const std::int32_t c = points[i][0] * dx - points[i][1] * dy;

        std::uint64_t hash = static_cast<std::uint32_t>(c);
        hash = (hash << 16) | static_cast<std::uint16_t>(dy);
        hash = (hash << 16) | static_cast<std::uint16_t>(dx);

        ++counts[hash];
      }
    }

    int maxCount{0};
    for (const auto& [hash, count] : counts) {
      if (count > maxCount) maxCount = count;
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
