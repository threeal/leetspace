#include <vector>

class NeighborSum {
 private:
  std::vector<std::vector<int>> grid;
  std::vector<std::size_t> ys;
  std::vector<std::size_t> xs;

 public:
  NeighborSum(std::vector<std::vector<int>>& grid)
      : grid{grid},
        ys(grid.size() * grid.size()),
        xs(grid.size() * grid.size()) {
    for (std::size_t y{0}; y < grid.size(); ++y) {
      for (std::size_t x{0}; x < grid[y].size(); ++x) {
        ys[grid[y][x]] = y;
        xs[grid[y][x]] = x;
      }
    }
  }

  int adjacentSum(int value) {
    const std::size_t y{ys[value]}, x{xs[value]};
    int sum{0};

    if (y > 0) sum += grid[y - 1][x];
    if (y + 1 < grid.size()) sum += grid[y + 1][x];
    if (x > 0) sum += grid[y][x - 1];
    if (x + 1 < grid[y].size()) sum += grid[y][x + 1];

    return sum;
  }

  int diagonalSum(int value) {
    const std::size_t y{ys[value]}, x{xs[value]};
    int sum{0};

    if (y > 0) {
      if (x > 0) sum += grid[y - 1][x - 1];
      if (x + 1 < grid[y - 1].size()) sum += grid[y - 1][x + 1];
    }

    if (y + 1 < grid.size()) {
      if (x > 0) sum += grid[y + 1][x - 1];
      if (x + 1 < grid[y + 1].size()) sum += grid[y + 1][x + 1];
    }

    return sum;
  }
};
