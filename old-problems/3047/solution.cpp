#include <algorithm>
#include <vector>

class Solution {
 public:
  long long largestSquareArea(
      std::vector<std::vector<int>>& bottomLeft,
      std::vector<std::vector<int>>& topRight) {
    int maxSide{0};
    for (std::size_t i{0}; i < bottomLeft.size(); ++i) {
      for (std::size_t j{i + 1}; j < topRight.size(); ++j) {
        const int width{
            std::min(topRight[i][0], topRight[j][0]) -
            std::max(bottomLeft[i][0], bottomLeft[j][0])};

        const int height{
            std::min(topRight[i][1], topRight[j][1]) -
            std::max(bottomLeft[i][1], bottomLeft[j][1])};

        const int side{std::min(width, height)};
        if (side > maxSide) maxSide = side;
      }
    }
    return static_cast<long long>(maxSide) * maxSide;
  }
};
