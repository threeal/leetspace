#include <vector>

enum class Dir {
  up,
  down,
  left,
  right
};

class Solution {
 public:
  bool hasValidPath(std::vector<std::vector<int>>& grid) {
    switch (grid[0][0]) {
      case 1:
      case 6:
        return follow(grid, Dir::right);

      case 2:
      case 3:
        return follow(grid, Dir::down);

      case 4:
        return follow(grid, Dir::right) || follow(grid, Dir::down);
    }
    return false;
  }

 private:
  static bool follow(std::vector<std::vector<int>>& grid, Dir dir) {
    std::size_t i{0}, j{0};
    const std::size_t ti{grid.size() - 1}, tj{grid[ti].size() - 1};
    while (i != ti || j != tj) {
      grid[i][j] = -1;
      switch (dir) {
        case Dir::up:
          if (i == 0) return false;
          switch (grid[--i][j]) {
            case 2:
              break;

            case 3:
              dir = Dir::left;
              break;

            case 4:
              dir = Dir::right;
              break;

            default:
              return false;
          }
          break;

        case Dir::down:
          if (i == ti) return false;
          switch (grid[++i][j]) {
            case 2:
              break;

            case 5:
              dir = Dir::left;
              break;

            case 6:
              dir = Dir::right;
              break;

            default:
              return false;
          }
          break;

        case Dir::left:
          if (j == 0) return false;
          switch (grid[i][--j]) {
            case 1:
              break;

            case 4:
              dir = Dir::down;
              break;

            case 6:
              dir = Dir::up;
              break;

            default:
              return false;
          }
          break;

        case Dir::right:
          if (j == tj) return false;
          switch (grid[i][++j]) {
            case 1:
              break;

            case 3:
              dir = Dir::down;
              break;

            case 5:
              dir = Dir::up;
              break;

            default:
              return false;
          }
          break;
      }
    }

    return true;
  }
};
