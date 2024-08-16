#include <vector>

class Solution {
 public:
  int numMagicSquaresInside(std::vector<std::vector<int>>& grid) {
    int num{0};
    for (int i = grid.size() - 2; i > 0; --i) {
      for (int j = grid[i].size() - 2; j > 0; --j) {
        if (grid[i][j] != 5) continue;
        switch (grid[i - 1][j - 1]) {
          case 2:
            switch (grid[i - 1][j]) {
              case 9:
                if (grid[i - 1][j + 1] == 4 && grid[i][j - 1] == 7 &&
                    grid[i][j + 1] == 3 && grid[i + 1][j - 1] == 6 &&
                    grid[i + 1][j] == 1 && grid[i + 1][j + 1] == 8) ++num;
                break;

              case 7:
                if (grid[i - 1][j + 1] == 6 && grid[i][j - 1] == 9 &&
                    grid[i][j + 1] == 1 && grid[i + 1][j - 1] == 4 &&
                    grid[i + 1][j] == 3 && grid[i + 1][j + 1] == 8) ++num;
                break;
            }
            break;

          case 4:
            switch (grid[i - 1][j]) {
              case 3:
                if (grid[i - 1][j + 1] == 8 && grid[i][j - 1] == 9 &&
                    grid[i][j + 1] == 1 && grid[i + 1][j - 1] == 2 &&
                    grid[i + 1][j] == 7 && grid[i + 1][j + 1] == 6) ++num;
                break;

              case 9:
                if (grid[i - 1][j + 1] == 2 && grid[i][j - 1] == 3 &&
                    grid[i][j + 1] == 7 && grid[i + 1][j - 1] == 8 &&
                    grid[i + 1][j] == 1 && grid[i + 1][j + 1] == 6) ++num;
                break;
            }
            break;

          case 6:
            switch (grid[i - 1][j]) {
              case 7:
                if (grid[i - 1][j + 1] == 2 && grid[i][j - 1] == 1 &&
                    grid[i][j + 1] == 9 && grid[i + 1][j - 1] == 8 &&
                    grid[i + 1][j] == 3 && grid[i + 1][j + 1] == 4) ++num;
                break;

              case 1:
                if (grid[i - 1][j + 1] == 8 && grid[i][j - 1] == 7 &&
                    grid[i][j + 1] == 3 && grid[i + 1][j - 1] == 2 &&
                    grid[i + 1][j] == 9 && grid[i + 1][j + 1] == 4) ++num;
                break;
            }
            break;

          case 8:
            switch (grid[i - 1][j]) {
              case 1:
                if (grid[i - 1][j + 1] == 6 && grid[i][j - 1] == 3 &&
                    grid[i][j + 1] == 7 && grid[i + 1][j - 1] == 4 &&
                    grid[i + 1][j] == 9 && grid[i + 1][j + 1] == 2) ++num;
                break;

              case 3:
                if (grid[i - 1][j + 1] == 4 && grid[i][j - 1] == 1 &&
                    grid[i][j + 1] == 9 && grid[i + 1][j - 1] == 6 &&
                    grid[i + 1][j] == 7 && grid[i + 1][j + 1] == 2) ++num;
                break;
            }
            break;
        }
      }
    }
    return num;
  }
};
