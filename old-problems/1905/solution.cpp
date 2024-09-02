#include <vector>

class Solution {
 public:
  int countSubIslands(
      std::vector<std::vector<int>>& grid1,
      std::vector<std::vector<int>>& grid2) {
    int count{0};
    for (std::size_t y{0}; y < grid2.size(); ++y) {
      for (std::size_t x{0}; x < grid2[y].size(); ++x) {
        if (grid2[y][x] == 0) continue;
        if (exploreSubisland(grid1, grid2, y, x)) ++count;
      }
    }

    return count;
  }

 private:
  static bool exploreSubisland(
      const std::vector<std::vector<int>>& grid1,
      std::vector<std::vector<int>>& grid2,
      std::size_t y, std::size_t x) {
    grid2[y][x] = 0;
    bool isSubisland = grid1[y][x] != 0;

    if (y > 0 && grid2[y - 1][x] != 0) {
      if (isSubisland) {
        isSubisland = exploreSubisland(grid1, grid2, y - 1, x);
      } else {
        exploreIsland(grid2, y - 1, x);
      }
    }

    if (y < grid2.size() - 1 && grid2[y + 1][x] != 0) {
      if (isSubisland) {
        isSubisland = exploreSubisland(grid1, grid2, y + 1, x);
      } else {
        exploreIsland(grid2, y + 1, x);
      }
    }

    if (x > 0 && grid2[y][x - 1] != 0) {
      if (isSubisland) {
        isSubisland = exploreSubisland(grid1, grid2, y, x - 1);
      } else {
        exploreIsland(grid2, y, x - 1);
      }
    }

    if (x < grid2[y].size() - 1 && grid2[y][x + 1] != 0) {
      if (isSubisland) {
        isSubisland = exploreSubisland(grid1, grid2, y, x + 1);
      } else {
        exploreIsland(grid2, y, x + 1);
      }
    }

    return isSubisland;
  }

  static void exploreIsland(
      std::vector<std::vector<int>>& grid, std::size_t y, std::size_t x) {
    grid[y][x] = 0;

    if (y > 0 && grid[y - 1][x] != 0) {
      exploreIsland(grid, y - 1, x);
    }

    if (y < grid.size() - 1 && grid[y + 1][x] != 0) {
      exploreIsland(grid, y + 1, x);
    }

    if (x > 0 && grid[y][x - 1] != 0) {
      exploreIsland(grid, y, x - 1);
    }

    if (x < grid[y].size() - 1 && grid[y][x + 1] != 0) {
      exploreIsland(grid, y, x + 1);
    }
  }
};
