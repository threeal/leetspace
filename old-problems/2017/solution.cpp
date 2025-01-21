#include <vector>

class Solution {
 public:
  long long gridGame(std::vector<std::vector<int>>& grid) {
    long long top{0};
    for (std::size_t i{1}; i < grid[0].size(); ++i) {
      top += grid[0][i];
    }

    long long min{top}, bottom{0};
    for (std::size_t i{1}; i < grid[0].size(); ++i) {
      top -= grid[0][i];
      bottom += grid[1][i - 1];
      if (top > bottom) {
        if (top < min) min = top;
      } else {
        if (bottom < min) min = bottom;
      }
    }

    return min;
  }
};
