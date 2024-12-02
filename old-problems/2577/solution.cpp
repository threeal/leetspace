#include <queue>
#include <tuple>
#include <vector>

using Cell = std::tuple<int, std::size_t, std::size_t>;

class Solution {
 public:
  int minimumTime(std::vector<std::vector<int>>& grid) {
    if (grid[0][1] > 1 && grid[1][0] > 1) return -1;

    std::size_t h{grid.size()}, w{grid.front().size()};

    std::priority_queue<Cell, std::vector<Cell>, std::greater<Cell>> queue{};

    queue.push({1, 0, 0});
    grid[0][0] = -1;

    while (!queue.empty()) {
      const auto [time, y, x] = queue.top();
      queue.pop();

      if (y == h - 1 && x == w - 1) return time - 1;

      if (y > 0 && grid[y - 1][x] >= 0) {
        int gridTime = grid[y - 1][x];
        if (gridTime <= time) {
          queue.push({time + 1, y - 1, x});
        } else {
          if ((gridTime - time) % 2 == 1) ++gridTime;
          queue.push({gridTime + 1, y - 1, x});
        }
        grid[y - 1][x] = -1;
      }

      if (y < h - 1 && grid[y + 1][x] >= 0) {
        int gridTime = grid[y + 1][x];
        if (gridTime <= time) {
          queue.push({time + 1, y + 1, x});
        } else {
          if ((gridTime - time) % 2 == 1) ++gridTime;
          queue.push({gridTime + 1, y + 1, x});
        }
        grid[y + 1][x] = -1;
      }

      if (x > 0 && grid[y][x - 1] >= 0) {
        int gridTime = grid[y][x - 1];
        if (gridTime <= time) {
          queue.push({time + 1, y, x - 1});
        } else {
          if ((gridTime - time) % 2 == 1) ++gridTime;
          queue.push({gridTime + 1, y, x - 1});
        }
        grid[y][x - 1] = -1;
      }

      if (x < w - 1 && grid[y][x + 1] >= 0) {
        int gridTime = grid[y][x + 1];
        if (gridTime <= time) {
          queue.push({time + 1, y, x + 1});
        } else {
          if ((gridTime - time) % 2 == 1) ++gridTime;
          queue.push({gridTime + 1, y, x + 1});
        }
        grid[y][x + 1] = -1;
      }
    }

    return -1;
  }
};
