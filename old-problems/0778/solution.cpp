#include <queue>
#include <tuple>
#include <vector>

class Solution {
 public:
  int swimInWater(std::vector<std::vector<int>>& grid) {
    std::priority_queue<std::tuple<int, std::size_t, std::size_t>> queue{};

    int maxHeight{grid[0][0]};
    queue.push({-grid[0][0], 0, 0});
    grid[0][0] = -1;

    while (!queue.empty()) {
      const auto [negHeight, y, x] = queue.top();

      if (-negHeight > maxHeight) maxHeight = -negHeight;
      if (y == grid.size() - 1 && x == grid[y].size() - 1) break;

      queue.pop();

      if (y > 0 && grid[y - 1][x] >= 0) {
        queue.push({-grid[y - 1][x], y - 1, x});
        grid[y - 1][x] = -1;
      }

      if (x > 0 && grid[y][x - 1] >= 0) {
        queue.push({-grid[y][x - 1], y, x - 1});
        grid[y][x - 1] = -1;
      }

      if (y + 1 < grid.size() && grid[y + 1][x] >= 0) {
        queue.push({-grid[y + 1][x], y + 1, x});
        grid[y + 1][x] = -1;
      }

      if (x + 1 < grid[y].size() && grid[y][x + 1] >= 0) {
        queue.push({-grid[y][x + 1], y, x + 1});
        grid[y][x + 1] = -1;
      }
    }

    return maxHeight;
  }
};
