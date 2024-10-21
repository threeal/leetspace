#include <vector>

class Solution {
 public:
  int minDays(std::vector<std::vector<int>>& grid) {
    const int h = grid.size();
    const int w =  grid.front().size();
    bool foundIsland{false};



    for (int y = h - 1; y >= 0; --y) {
      for (int x = w - 1; x >= 0; --x) {
        if (grid[y][x] == 0) continue;

        if (foundIsland) return 0;
        foundIsland = true;

        exploreIsland(grid.data(), h, w, y, x, -1, -1);
      }
    }

    return 2;
  }

  void exploreIsland(
      std::vector<int>* grid, int h, int w, int y, int x, int py, int px) {
    grid[y][x] = 0;

    if (y > 0 && py != y - 1 && grid[y - 1][x] == 1) {
      exploreIsland(grid, h, w, y - 1, x);
    }

    if (y < h - 1 && py != y + 1 && grid[y + 1][x] == 1) {
      exploreIsland(grid, h, w, y + 1, x);
    }

    if (x > 0 && px != x - 1 && grid[y][x - 1] == 1) {
      exploreIsland(grid, h, w, y, x - 1);
    }

    if (x < w - 1 && grid[y][x + 1] == 1) {
      exploreIsland(grid, h, w, y, x + 1);
    }
  }
};
