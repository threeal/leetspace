#include <array>
#include <vector>

struct Coord {
  int y;
  int x;
};

struct Cell {
  bool isWater;
  Coord leftParent;
  Coord rightParent;
};

static std::array<Coord, 8> directions{
    {{-1, 0}, {-1, -1}, {0, -1}, {1, -1}, {1, 0}, {1, 1}, {0, 1}, {-1, 1}}};

class Solution {
 public:
  int latestDayToCross(int row, int col, std::vector<std::vector<int>>& cells) {
    std::vector<std::vector<Cell>> grid(
        row + 2, std::vector<Cell>(col + 2, {.isWater = false}));

    for (std::size_t day{0}; day < cells.size(); ++day) {
      const int y{cells[day][0]};
      const int x{cells[day][1]};

      Cell& cell{grid[y][x]};
      cell.isWater = true;
      cell.leftParent.y = y;
      cell.leftParent.x = x;
      cell.rightParent.y = y;
      cell.rightParent.x = x;

      for (const Coord& dir : directions) {
        const int yy{y + dir.y}, xx{x + dir.x};
        if (grid[yy][xx].isWater) {
          const Coord& leftParent{findLeftParent(grid, yy, xx)};
          if (leftParent.x < cell.leftParent.x) {
            cell.leftParent = leftParent;
          }

          const Coord& rightParent{findRightParent(grid, yy, xx)};
          if (rightParent.x > cell.rightParent.x) {
            cell.rightParent = rightParent;
          }
        }
      }

      if (cell.leftParent.x == 1 && cell.rightParent.x == col) return day;

      for (const Coord& dir : directions) {
        const int yy{y + dir.y}, xx{x + dir.x};
        if (grid[yy][xx].isWater) {
          const Coord& leftParent{findLeftParent(grid, yy, xx)};
          if (leftParent.x >= cell.leftParent.x) {
            grid[leftParent.y][leftParent.x].leftParent = cell.leftParent;
          }

          const Coord& rightParent{findRightParent(grid, yy, xx)};
          if (rightParent.x <= cell.rightParent.x) {
            grid[rightParent.y][rightParent.x].rightParent = cell.rightParent;
          }
        }
      }
    }

    return -1;
  }

 private:
  const Coord& findLeftParent(
      std::vector<std::vector<Cell>>& grid, int y, int x) {
    Coord& p{grid[y][x].leftParent};
    return (p.y != y || p.x != x)
        ? grid[y][x].leftParent = findLeftParent(grid, p.y, p.x)
        : p;
  }

  const Coord& findRightParent(
      std::vector<std::vector<Cell>>& grid, int y, int x) {
    Coord& p{grid[y][x].rightParent};
    return (p.y != y || p.x != x)
        ? grid[y][x].rightParent = findRightParent(grid, p.y, p.x)
        : p;
  }
};
