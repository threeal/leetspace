#include <vector>

class Solution {
 public:
  int maxAreaOfIsland(std::vector<std::vector<int>>& grid) {
    int maxArea{0};
    for (std::size_t y{0}; y < grid.size(); ++y) {
      for (std::size_t x{0}; x < grid[y].size(); ++x) {
        if (grid[y][x] == 1) {
          const int area{explore(grid, y, x)};
          if (area > maxArea) maxArea = area;
        }
      }
    }
    return maxArea;
  }

 private:
  static int explore(
      std::vector<std::vector<int>>& grid, std::size_t y, std::size_t x) {
    grid[y][x] = 0;
    int area{1};

    if (y > 0 && grid[y - 1][x] == 1) {
      area += explore(grid, y - 1, x);
    }

    if (y + 1 < grid.size() && grid[y + 1][x] == 1) {
      area += explore(grid, y + 1, x);
    }

    if (x > 0 && grid[y][x - 1] == 1) {
      area += explore(grid, y, x - 1);
    }

    if (x + 1 < grid[y].size() && grid[y][x + 1] == 1) {
      area += explore(grid, y, x + 1);
    }

    return area;
  }
};
