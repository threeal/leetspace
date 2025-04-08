#include <queue>
#include <tuple>
#include <vector>

class Solution {
 private:
  using Cell = std::tuple<int, std::size_t, std::size_t>;

 public:
  int trapRainWater(std::vector<std::vector<int>>& heightMap) {
    const std::size_t my{heightMap.size()}, mx{heightMap[0].size()};

    std::priority_queue<Cell, std::vector<Cell>, std::greater<Cell>> cells{};

    for (std::size_t i{0}; i < my; ++i) {
      cells.push({heightMap[i][0], i, 0});
      heightMap[i][0] = -1;

      cells.push({heightMap[i][mx - 1], i, mx - 1});
      heightMap[i][mx - 1] = -1;
    }

    for (std::size_t i{1}; i < mx - 1; ++i) {
      cells.push({heightMap[0][i], 0, i});
      heightMap[0][i] = -1;

      cells.push({heightMap[my - 1][i], my - 1, i});
      heightMap[my - 1][i] = -1;
    }

    int volume{0};
    while (!cells.empty()) {
      const auto [height, y, x] = cells.top();
      cells.pop();

      if (y > 0 && heightMap[y - 1][x] >= 0) {
        if (height > heightMap[y - 1][x]) {
          volume += height - heightMap[y - 1][x];
          cells.push({height, y - 1, x});
        } else {
          cells.push({heightMap[y - 1][x], y - 1, x});
        }
        heightMap[y - 1][x] = -1;
      }

      if (y + 1 < my && heightMap[y + 1][x] >= 0) {
        if (height > heightMap[y + 1][x]) {
          volume += height - heightMap[y + 1][x];
          cells.push({height, y + 1, x});
        } else {
          cells.push({heightMap[y + 1][x], y + 1, x});
        }
        heightMap[y + 1][x] = -1;
      }

      if (x > 0 && heightMap[y][x - 1] >= 0) {
        if (height > heightMap[y][x - 1]) {
          volume += height - heightMap[y][x - 1];
          cells.push({height, y, x - 1});
        } else {
          cells.push({heightMap[y][x - 1], y, x - 1});
        }
        heightMap[y][x - 1] = -1;
      }

      if (x + 1 < mx && heightMap[y][x + 1] >= 0) {
        if (height > heightMap[y][x + 1]) {
          volume += height - heightMap[y][x + 1];
          cells.push({height, y, x + 1});
        } else {
          cells.push({heightMap[y][x + 1], y, x + 1});
        }
        heightMap[y][x + 1] = -1;
      }
    }

    return volume;
  }
};
