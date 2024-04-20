#include <vector>

class Solution {
 public:
  int islandPerimeter(std::vector<std::vector<int>>& grid) {
    int perimeter{0};

    if (grid[0][0] == 1) {
      perimeter += 4;
    }

    for (std::size_t j{1}; j < grid[0].size(); ++j) {
      if (grid[0][j] == 1) {
        perimeter += grid[0][j - 1] == 0 ? 4 : 2;
      }
    }

    for (std::size_t i{1}; i < grid.size(); ++i) {
      if (grid[i][0] == 1) {
        perimeter += grid[i - 1][0] == 0 ? 4 : 2;
      }

      for (std::size_t j{1}; j < grid[i].size(); ++j) {
        if (grid[i][j] == 1) {
          if (grid[i - 1][j] == 0) {
            if (grid[i][j - 1] == 0) {
              perimeter += 4;
            } else {
              perimeter += 2;
            }
          } else if (grid[i][j - 1] == 0) {
            perimeter += 2;
          }
        }
      }
    }

    return perimeter;
  }
};
