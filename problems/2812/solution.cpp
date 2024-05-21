#include <algorithm>
#include <limits>
#include <queue>
#include <tuple>
#include <vector>

class Solution {
 public:
  int maximumSafenessFactor(std::vector<std::vector<int>>& grid) {
    const int h = grid.size();
    const int w = grid.front().size();

    std::queue<std::tuple<int, int>> thiefs{};
    for (int y{h - 1}; y >= 0; --y) {
      for (int x{w - 1}; x >= 0; --x) {
        if (grid[y][x] == 1) {
          grid[y][x] = 0;
          thiefs.push({y, x});
        } else {
          grid[y][x] = std::numeric_limits<int>::max();
        }
      }
    }

    for (int step{1}; !thiefs.empty(); ++step) {
      for (std::size_t i{thiefs.size()}; i > 0; --i) {
        const auto [y, x] = thiefs.front();
        if (y > 0 && step < grid[y - 1][x]) {
          grid[y - 1][x] = step;
          thiefs.push({y - 1, x});
        }
        if (x > 0 && step < grid[y][x - 1]) {
          grid[y][x - 1] = step;
          thiefs.push({y, x - 1});
        }
        if (y + 1 < h && step < grid[y + 1][x]) {
          grid[y + 1][x] = step;
          thiefs.push({y + 1, x});
        }
        if (x + 1 < w && step < grid[y][x + 1]) {
          grid[y][x + 1] = step;
          thiefs.push({y, x + 1});
        }
        thiefs.pop();
      }
    }

    std::priority_queue<std::tuple<int, int, int>> steps{};
    std::vector<std::vector<bool>> visited(h, std::vector(w, false));

    steps.push({grid[0][0], 0, 0});
    visited[0][0] = true;

    while (!steps.empty()) {
      const auto [score, y, x] = steps.top();
      if (y == h - 1 && x == w - 1) return score;
      steps.pop();

      if (y > 0 && !visited[y - 1][x]) {
        steps.push({std::min(score, grid[y - 1][x]), y - 1, x});
        visited[y - 1][x] = true;
      }

      if (x > 0 && !visited[y][x - 1]) {
        steps.push({std::min(score, grid[y][x - 1]), y, x - 1});
        visited[y][x - 1] = true;
      }

      if (y + 1 < w && !visited[y + 1][x]) {
        steps.push({std::min(score, grid[y + 1][x]), y + 1, x});
        visited[y + 1][x] = true;
      }

      if (x + 1 < h && !visited[y][x + 1]) {
        steps.push({std::min(score, grid[y][x + 1]), y, x + 1});
        visited[y][x + 1] = true;
      }
    }

    return 0;
  }
};
