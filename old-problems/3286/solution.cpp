#include <limits>
#include <queue>
#include <vector>

struct Cell {
  std::size_t y;
  std::size_t x;
  int health;

  bool operator<(const Cell& other) const {
    return this->health < other.health;
  }
};

class Solution {
 public:
  bool findSafeWalk(std::vector<std::vector<int>>& grid, int health) {
    const std::size_t m{grid.size() - 1}, n{grid[0].size() - 1};
    if (health > grid[0][0]) {
      std::priority_queue<Cell> cells{};
      cells.push({0, 0, health - grid[0][0]});
      grid[0][0] = std::numeric_limits<int>::max();

      while (!cells.empty()) {
        const Cell cell{cells.top()};
        cells.pop();

        if (cell.y > 0) {
          const int nextHealth{grid[cell.y - 1][cell.x]};
          if (cell.health > nextHealth) {
            cells.push({cell.y - 1, cell.x, cell.health - nextHealth});
            grid[cell.y - 1][cell.x] = std::numeric_limits<int>::max();
          }
        }

        if (cell.y < m) {
          const int nextHealth{grid[cell.y + 1][cell.x]};
          if (cell.health > nextHealth) {
            if (cell.y + 1 == m && cell.x == n) return true;
            cells.push({cell.y + 1, cell.x, cell.health - nextHealth});
            grid[cell.y + 1][cell.x] = std::numeric_limits<int>::max();
          }
        }

        if (cell.x > 0) {
          const int nextHealth{grid[cell.y][cell.x - 1]};
          if (cell.health > nextHealth) {
            cells.push({cell.y, cell.x - 1, cell.health - nextHealth});
            grid[cell.y][cell.x - 1] = std::numeric_limits<int>::max();
          }
        }

        if (cell.x < n) {
          const int nextHealth{grid[cell.y][cell.x + 1]};
          if (cell.health > nextHealth) {
            if (cell.y == m && cell.x + 1 == n) return true;
            cells.push({cell.y, cell.x + 1, cell.health - nextHealth});
            grid[cell.y][cell.x + 1] = std::numeric_limits<int>::max();
          }
        }
      }
    }
    return false;
  }
};
