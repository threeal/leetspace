#include <queue>
#include <vector>

struct Position {
  int y;
  int x;
  bool horizontal;
};

class Solution {
 public:
  int minimumMoves(std::vector<std::vector<int>>& grid) {
    const int height = grid.size();
    const int width = grid.front().size();

    std::vector<std::vector<bool>> horizontalSeen(height, std::vector<bool>(width, false));
    std::vector<std::vector<bool>> verticalSeen(height, std::vector<bool>(width, false));

    std::queue<Position> positions;
    positions.push({.y = 0, .x = 0, .horizontal = true});
    horizontalSeen[0][0] = true;

    for (int step{0}; !positions.empty(); ++step) {
      for (std::size_t i{positions.size()}; i > 0; --i) {
        const auto [y, x, horizontal] = positions.front();
        if (y == height - 1 && x == width - 2 && horizontal) return step;
        positions.pop();

        if (horizontal) {
          if (y + 1 < height && !grid[y + 1][x] && !grid[y + 1][x + 1]) {
            if (!horizontalSeen[y + 1][x]) {
              positions.push({.y = y + 1, .x = x, .horizontal = true});
              horizontalSeen[y + 1][x] = true;
            }

            if (!verticalSeen[y][x]) {
              positions.push({.y = y, .x = x, .horizontal = false});
              verticalSeen[y][x] = true;
            }
          }

          if (x + 2 < width && !grid[y][x + 2] && !horizontalSeen[y][x + 1]) {
            positions.push({.y = y, .x = x + 1, .horizontal = true});
            horizontalSeen[y][x + 1] = true;
          }
        } else {
          verticalSeen[y][x] = true;
          if (y + 2 < height && !grid[y + 2][x] && !verticalSeen[y + 1][x]) {
            positions.push({.y = y + 1, .x = x, .horizontal = false});
            verticalSeen[y + 1][x] = true;
          }

          if (x + 1 < width && !grid[y][x + 1] && !grid[y + 1][x + 1]) {
            if (!verticalSeen[y][x + 1]) {
              positions.push({.y = y, .x = x + 1, .horizontal = false});
              verticalSeen[y][x + 1] = true;
            }

            if (!horizontalSeen[y][x]) {
              positions.push({.y = y, .x = x, .horizontal = true});
              horizontalSeen[y][x] = true;
            }
          }
        }
      }
    }

    return -1;
  }
};
