#include <queue>
#include <tuple>
#include <vector>

class Solution {
 public:
  int minimumObstacles(std::vector<std::vector<int>>& grid) {
    const std::size_t h{grid.size()}, w{grid.front().size()};

    std::queue<std::tuple<std::size_t, std::size_t>> currs{}, nexts{};
    currs.push({0, 0});

    int removal{grid[0][0]};
    grid[0][0] = -1;

    while (!currs.empty()) {
      while (!currs.empty()) {
        const auto [y, x] = currs.front();
        if (y == h - 1 && x == w - 1) return removal;
        currs.pop();

        if (y > 0 && grid[y - 1][x] >= 0) {
          if (grid[y - 1][x] == 0) {
            currs.push({y - 1, x});
          } else {
            nexts.push({y - 1, x});
          }
          grid[y - 1][x] = -1;
        }

        if (y < h - 1 && grid[y + 1][x] >= 0) {
          if (grid[y + 1][x] == 0) {
            currs.push({y + 1, x});
          } else {
            nexts.push({y + 1, x});
          }
          grid[y + 1][x] = -1;
        }

        if (x > 0 && grid[y][x - 1] >= 0) {
          if (grid[y][x - 1] == 0) {
            currs.push({y, x - 1});
          } else {
            nexts.push({y, x - 1});
          }
          grid[y][x - 1] = -1;
        }

        if (x < w - 1 && grid[y][x + 1] >= 0) {
          if (grid[y][x + 1] == 0) {
            currs.push({y, x + 1});
          } else {
            nexts.push({y, x + 1});
          }
          grid[y][x + 1] = -1;
        }
      }

      std::swap(currs, nexts);
      ++removal;
    }

    return -1;
  }
};
