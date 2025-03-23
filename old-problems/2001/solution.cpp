#include <algorithm>
#include <numeric>
#include <vector>

class Solution {
 public:
  long long interchangeableRectangles(
      std::vector<std::vector<int>>& rectangles) {
    for (auto& rectangle : rectangles) {
      const int gcd{std::gcd(rectangle[0], rectangle[1])};
      rectangle[0] /= gcd;
      rectangle[1] /= gcd;
    }

    std::sort(rectangles.begin(), rectangles.end());

    long long totalCount{0}, count{0};
    for (std::size_t i{1}; i < rectangles.size(); ++i) {
      if (rectangles[i][0] == rectangles[i - 1][0] &&
          rectangles[i][1] == rectangles[i - 1][1]) {
        totalCount += ++count;
      } else {
        count = 0;
      }
    }

    return totalCount;
  }
};
