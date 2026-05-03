#include <vector>

class Solution {
 public:
  int numberOfSubmatrices(std::vector<std::vector<char>>& grid) {
    int count{0};
    std::vector<int> xs(grid[0].size(), 0), ys(grid[0].size(), 0);
    for (std::size_t i{0}; i < grid.size(); ++i) {
      int x{0}, y{0};
      for (std::size_t j{0}; j < grid[i].size(); ++j) {
        switch (grid[i][j]) {
          case 'X':
            ++x;
            break;

          case 'Y':
            ++y;
            break;
        }

        if (xs[j] + x != 0 && xs[j] + x == ys[j] + y) ++count;

        xs[j] += x;
        ys[j] += y;
      }
    }
    return count;
  }
};
