#include <queue>
#include <vector>

class Solution {
 public:
  int trapRainWater(std::vector<std::vector<int>>& heightMap) {
    const std::size_t h{heightMap.size()}, w{heightMap.front().size()};
    std::vector<std::vector<bool>> visited(h, std::vector<bool>(w, false));
    std::priority_queue<std::tuple<int, std::size_t, std::size_t>> queue{};

    for (std::size_t y{0}; y < h; ++y) {
      visited[y][0] = true;
      queue.push({ heightMap[y][0], y, 0 });

      visited[y][w - 1] = true;
      queue.push({ heightMap[y][w - 1], y, w - 1 });
    }

    for (std::size_t x{1}; x < w - 1; ++x) {
      visited[0][x] = true;
      queue.push({ heightMap[0][x], 0, x });

      visited[h - 1][x] = true;
      queue.push({ heightMap[h - 1][x], h - 1, x });
    }

    while (!queue.empty()) {
      const [height,
      queue.pop();
    }

    return heightMap.size();
  }
};
