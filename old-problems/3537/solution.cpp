#include <vector>

class Solution {
 public:
  std::vector<std::vector<int>> specialGrid(int n) {
    if (n == 0) return {{0}};

    std::size_t width{1};
    while (n > 0) {
      width *= 2;
      --n;
    }

    std::vector<std::vector<int>> grid(width, std::vector<int>(width));
    fill(grid, 0, 0, width, 0);

    return grid;
  }

 private:
  static void fill(
      std::vector<std::vector<int>>& grid,
      std::size_t y, std::size_t x, std::size_t width, int min) {
    if (width == 2) {
      grid[y][x + 1] = min;
      grid[y + 1][x + 1] = min + 1;
      grid[y + 1][x] = min + 2;
      grid[y][x] = min + 3;
    } else {
      const std::size_t half{width / 2};
      const std::size_t area{half * half};
      fill(grid, y, x + half, half, min);
      fill(grid, y + half, x + half, half, min + area);
      fill(grid, y + half, x, half, min + 2 * area);
      fill(grid, y, x, half, min + 3 * area);
    }
  }
};
