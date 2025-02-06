#include <queue>
#include <vector>

class Solution {
 public:
  int largestIsland(std::vector<std::vector<int>>& grid) {
    std::vector<int> islandSizes{};
    for (std::size_t y{0}; y < grid.size(); ++y) {
      for (std::size_t x{0}; x < grid[y].size(); ++x) {
        if (grid[y][x] == 1) {
          const int size = exploreIsland(grid, 2 + islandSizes.size(), y, x);
          islandSizes.push_back(size);
        }
      }
    }

    int maxIslandSize{0};
    for (const auto size : islandSizes) {
      if (size > maxIslandSize) maxIslandSize = size;
    }

    for (std::size_t y{0}; y < grid.size(); ++y) {
      for (std::size_t x{0}; x < grid[y].size(); ++x) {
        if (grid[y][x] == 0) {
          const int size = 1 + checkTopIsland(grid, islandSizes, y, x);
          if (size > maxIslandSize) maxIslandSize = size;
        }
      }
    }

    return maxIslandSize;
  }

 private:
  static int exploreIsland(
      std::vector<std::vector<int>>& grid, int islandId,
      std::size_t y, std::size_t x) {
    int size{1};
    grid[y][x] = islandId;

    if (y > 0 && grid[y - 1][x] == 1) {
      size += exploreIsland(grid, islandId, y - 1, x);
    }

    if (x > 0 && grid[y][x - 1] == 1) {
      size += exploreIsland(grid, islandId, y, x - 1);
    }

    if (y < grid.size() - 1 && grid[y + 1][x] == 1) {
      size += exploreIsland(grid, islandId, y + 1, x);
    }

    if (x < grid[y].size() - 1 && grid[y][x + 1] == 1) {
      size += exploreIsland(grid, islandId, y, x + 1);
    }

    return size;
  }

  static int checkTopIsland(
      std::vector<std::vector<int>>& grid,
      std::vector<int>& islandSizes,
      std::size_t y, std::size_t x) {
    if (y > 0 && grid[y - 1][x] > 1) {
      const int topSize = islandSizes[grid[y - 1][x] - 2];
      islandSizes[grid[y - 1][x] - 2] = 0;
      const int size = checkLeftIsland(grid, islandSizes, y, x);
      islandSizes[grid[y - 1][x] - 2] = topSize;
      return topSize + size;
    } else {
      return checkLeftIsland(grid, islandSizes, y, x);
    }
  }

  static int checkLeftIsland(
      std::vector<std::vector<int>>& grid,
      std::vector<int>& islandSizes,
      std::size_t y, std::size_t x) {
    if (x > 0 && grid[y][x - 1] > 1) {
      const int leftSize = islandSizes[grid[y][x - 1] - 2];
      islandSizes[grid[y][x - 1] - 2] = 0;
      const int size = checkBottomIsland(grid, islandSizes, y, x);
      islandSizes[grid[y][x - 1] - 2] = leftSize;
      return leftSize + size;
    } else {
      return checkBottomIsland(grid, islandSizes, y, x);
    }
  }

  static int checkBottomIsland(
      std::vector<std::vector<int>>& grid,
      std::vector<int>& islandSizes,
      std::size_t y, std::size_t x) {
    if (y < grid.size() - 1 && grid[y + 1][x] > 1) {
      const int topSize = islandSizes[grid[y + 1][x] - 2];
      islandSizes[grid[y + 1][x] - 2] = 0;
      const int size = checkRightIsland(grid, islandSizes, y, x);
      islandSizes[grid[y + 1][x] - 2] = topSize;
      return topSize + size;
    } else {
      return checkRightIsland(grid, islandSizes, y, x);
    }
  }

  static int checkRightIsland(
      std::vector<std::vector<int>>& grid,
      std::vector<int>& islandSizes,
      std::size_t y, std::size_t x) {
    return (x < grid[y].size() - 1 && grid[y][x + 1] > 1)
        ? islandSizes[grid[y][x + 1] - 2]
        : 0;
  }
};
