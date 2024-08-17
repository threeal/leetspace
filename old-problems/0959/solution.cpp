#include <string>
#include <vector>

class Solution {
 public:
  int regionsBySlashes(std::vector<std::string>& grid) {
    const int n = grid.size();
    for (auto& line : grid) {
      for (auto& c : line) {
        switch (c) {
          // clang-format off
          case ' ': c = 0b000000; break;
          case '/': c = 0b000001; break;
          case '\\': c = 0b000011; break;
            // clang-format on
        }
      }
    }

    int regions{0};
    for (int y = n - 1; y >= 0; --y) {
      for (int x = n - 1; x >= 0; --x) {
        switch (grid[y][x] & 0b000011) {
          case 0b000000:
            if ((grid[y][x] & 0b111100) == 0b000000) {
              ++regions;
              grid[y][x] |= 0b111100;
              if (x > 0) markLeft(grid.data(), n, y, x - 1);
              if (x < n - 1) markRight(grid.data(), n, y, x + 1);
              if (y > 0) markTop(grid.data(), n, y - 1, x);
              if (y < n - 1) markBottom(grid.data(), n, y + 1, x);
            }
            break;

          case 0b000001:
            if ((grid[y][x] & 0b101000) == 0b000000) {
              ++regions;
              grid[y][x] |= 0b101000;
              if (x > 0) markLeft(grid.data(), n, y, x - 1);
              if (y > 0) markTop(grid.data(), n, y - 1, x);
            }

            if ((grid[y][x] & 0b010100) == 0b000000) {
              ++regions;
              grid[y][x] |= 0b010100;
              if (x < n - 1) markRight(grid.data(), n, y, x + 1);
              if (y < n - 1) markBottom(grid.data(), n, y + 1, x);
            }
            break;

          case 0b000011:
            if ((grid[y][x] & 0b100100) == 0b000000) {
              ++regions;
              grid[y][x] |= 0b100100;
              if (x > 0) markLeft(grid.data(), n, y, x - 1);
              if (y < n - 1) markBottom(grid.data(), n, y + 1, x);
            }

            if ((grid[y][x] & 0b011000) == 0b000000) {
              ++regions;
              grid[y][x] |= 0b011000;
              if (x < n - 1) markRight(grid.data(), n, y, x + 1);
              if (y > 0) markTop(grid.data(), n, y - 1, x);
            }
            break;
        }
      }
    }

    return regions;
  }

  void markLeft(std::string* grid, int n, int y, int x) {
    switch (grid[y][x] & 0b000011) {
      case 0b000000:
        if ((grid[y][x] & 0b111100) == 0b000000) {
          grid[y][x] |= 0b111100;
          if (x > 0) markLeft(grid, n, y, x - 1);
          if (y > 0) markTop(grid, n, y - 1, x);
          if (y < n - 1) markBottom(grid, n, y + 1, x);
        }
        break;

      case 0b000001:
        if ((grid[y][x] & 0b010100) == 0b000000) {
          grid[y][x] |= 0b010100;
          if (y < n - 1) markBottom(grid, n, y + 1, x);
        }
        break;

      case 0b000011:
        if ((grid[y][x] & 0b011000) == 0b000000) {
          grid[y][x] |= 0b011000;
          if (y > 0) markTop(grid, n, y - 1, x);
        }
        break;
    }
  }

  void markRight(std::string* grid, int n, int y, int x) {
    switch (grid[y][x] & 0b000011) {
      case 0b000000:
        if ((grid[y][x] & 0b111100) == 0b000000) {
          grid[y][x] |= 0b111100;
          if (x < n - 1) markRight(grid, n, y, x + 1);
          if (y > 0) markTop(grid, n, y - 1, x);
          if (y < n - 1) markBottom(grid, n, y + 1, x);
        }
        break;

      case 0b000001:
        if ((grid[y][x] & 0b101000) == 0b000000) {
          grid[y][x] |= 0b101000;
          if (y > 0) markTop(grid, n, y - 1, x);
        }
        break;

      case 0b000011:
        if ((grid[y][x] & 0b100100) == 0b000000) {
          grid[y][x] |= 0b100100;
          if (y < n - 1) markBottom(grid, n, y + 1, x);
        }
        break;
    }
  }

  void markTop(std::string* grid, int n, int y, int x) {
    switch (grid[y][x] & 0b000011) {
      case 0b000000:
        if ((grid[y][x] & 0b111100) == 0b000000) {
          grid[y][x] |= 0b111100;
          if (x > 0) markLeft(grid, n, y, x - 1);
          if (x < n - 1) markRight(grid, n, y, x + 1);
          if (y > 0) markTop(grid, n, y - 1, x);
        }
        break;

      case 0b000001:
        if ((grid[y][x] & 0b010100) == 0b000000) {
          grid[y][x] |= 0b010100;
          if (x < n - 1) markRight(grid, n, y, x + 1);
        }
        break;

      case 0b000011:
        if ((grid[y][x] & 0b100100) == 0b000000) {
          grid[y][x] |= 0b100100;
          if (x > 0) markLeft(grid, n, y, x - 1);
        }
        break;
    }
  }

  void markBottom(std::string* grid, int n, int y, int x) {
    switch (grid[y][x] & 0b000011) {
      case 0b000000:
        if ((grid[y][x] & 0b111100) == 0b000000) {
          grid[y][x] |= 0b111100;
          if (x > 0) markLeft(grid, n, y, x - 1);
          if (x < n - 1) markRight(grid, n, y, x + 1);
          if (y < n - 1) markBottom(grid, n, y + 1, x);
        }
        break;

      case 0b000001:
        if ((grid[y][x] & 0b101000) == 0b000000) {
          grid[y][x] |= 0b101000;
          if (x > 0) markLeft(grid, n, y, x - 1);
        }
        break;

      case 0b000011:
        if ((grid[y][x] & 0b011000) == 0b000000) {
          grid[y][x] |= 0b011000;
          if (x < n - 1) markRight(grid, n, y, x + 1);
        }
        break;
    }
  }
};
