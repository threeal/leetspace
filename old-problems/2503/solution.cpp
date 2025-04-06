#include <algorithm>
#include <numeric>
#include <queue>
#include <tuple>
#include <utility>
#include <vector>

class Solution {
 private:
  using Cell = std::tuple<int, std::size_t, std::size_t>;

 public:
  std::vector<int> maxPoints(
      std::vector<std::vector<int>>& grid, std::vector<int>& queries) {
    std::vector<std::size_t> indices(queries.size());
    std::iota(indices.begin(), indices.end(), 0);

    std::sort(indices.begin(), indices.end(), [&](const auto a, const auto b) {
      return queries[a] < queries[b];
    });

    int count{0};
    std::priority_queue<Cell, std::vector<Cell>, std::greater<Cell>> cells;

    cells.push({grid[0][0], 0, 0});
    grid[0][0] = 0;

    for (const auto index : indices) {
      while (!cells.empty() && std::get<0>(cells.top()) < queries[index]) {
        ++count;

        const auto y = std::get<1>(cells.top());
        const auto x = std::get<2>(cells.top());
        cells.pop();

        if (y > 0 && grid[y - 1][x] > 0) {
          cells.push({grid[y - 1][x], y - 1, x});
          grid[y - 1][x] = 0;
        }

        if (x > 0 && grid[y][x - 1] > 0) {
          cells.push({grid[y][x - 1], y, x - 1});
          grid[y][x - 1] = 0;
        }

        if (y < grid.size() - 1 && grid[y + 1][x] > 0) {
          cells.push({grid[y + 1][x], y + 1, x});
          grid[y + 1][x] = 0;
        }

        if (x < grid[y].size() - 1 && grid[y][x + 1] > 0) {
          cells.push({grid[y][x + 1], y, x + 1});
          grid[y][x + 1] = 0;
        }
      }
      queries[index] = count;
    }

    return queries;
  }
};
