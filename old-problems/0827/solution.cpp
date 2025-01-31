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
          std::vector<bool> visited(islandSizes.size(), false);
          int size{1};

          if (y > 0 && grid[y - 1][x] > 1 && !visited[grid[y - 1][x] - 2]) {
            visited[grid[y - 1][x] - 2] = true;
            size += islandSizes[grid[y - 1][x] - 2];
          }

          if (x > 0 && grid[y][x - 1] > 1 && !visited[grid[y][x - 1] - 2]) {
            visited[grid[y][x - 1] - 2] = true;
            size += islandSizes[grid[y][x - 1] - 2];
          }

          if (y < grid.size() - 1 && grid[y + 1][x] > 1 &&
              !visited[grid[y + 1][x] - 2]) {
            visited[grid[y + 1][x] - 2] = true;
            size += islandSizes[grid[y + 1][x] - 2];
          }

          if (x < grid[y].size() - 1 && grid[y][x + 1] > 1 &&
              !visited[grid[y][x + 1] - 2]) {
            visited[grid[y][x + 1] - 2] = true;
            size += islandSizes[grid[y][x + 1] - 2];
          }

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
};
