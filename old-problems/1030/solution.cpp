#include <queue>
#include <tuple>
#include <vector>

class Solution {
 public:
  std::vector<std::vector<int>> allCellsDistOrder(
      int rows, int cols, int rCenter, int cCenter) {
    std::vector<std::vector<int>> output{};
    output.reserve(rows * cols);

    std::queue<std::tuple<int, int>> cells{};
    std::vector<std::vector<bool>> visited(
        rows, std::vector<bool>(cols, false));

    cells.push({rCenter, cCenter});
    visited[rCenter][cCenter] = true;

    while (!cells.empty()) {
      const auto [y, x] = cells.front();
      cells.pop();

      output.push_back({y, x});

      if (y > 0 && !visited[y - 1][x]) {
        cells.push({y - 1, x});
        visited[y - 1][x] = true;
      }

      if (y + 1 < rows && !visited[y + 1][x]) {
        cells.push({y + 1, x});
        visited[y + 1][x] = true;
      }

      if (x > 0 && !visited[y][x - 1]) {
        cells.push({y, x - 1});
        visited[y][x - 1] = true;
      }

      if (x + 1 < cols && !visited[y][x + 1]) {
        cells.push({y, x + 1});
        visited[y][x + 1] = true;
      }
    }

    return output;
  }
};
