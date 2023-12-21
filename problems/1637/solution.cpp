#include <algorithm>
#include <unordered_set>
#include <vector>

class Solution {
 public:
  int maxWidthOfVerticalArea(std::vector<std::vector<int>>& points) {
    std::unordered_set<int> unique_xs;
    for (const auto& point : points) {
      unique_xs.insert(point[0]);
    }

    std::vector<int> xs(unique_xs.size());
    int i = -1;
    for (const auto& x : unique_xs) {
      xs[++i] = x;
    }

    std::sort(xs.begin(), xs.end());

    int max_width = 0;
    for (std::size_t i = 1; i < xs.size(); ++i) {
      max_width = std::max(max_width, xs[i] - xs[i - 1]);
    }

    return max_width;
  }
};
