#include <vector>

class Solution {
 public:
  int minimumArea(std::vector<std::vector<int>>& grid) {
    std::size_t t{grid.size() - 1};
    std::size_t l{grid[0].size() - 1};
    std::size_t b{0};
    std::size_t r{0};

    for (std::size_t i{0}; i < grid.size(); ++i) {
      bool has_one{false};
      for (std::size_t j{0}; j < grid[i].size(); ++j) {
        if (grid[i][j] == 1) {
          has_one = true;

          if (j < l) l = j;
          if (j > r) r = j;
        }
      }

      if (has_one) {
        if (i < t) t = i;
        if (i > b) b = i;
      }
    }

    return (b - t + 1) * (r - l + 1);
  }
};
