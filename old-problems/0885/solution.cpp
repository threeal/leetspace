#include <vector>

class Solution {
 public:
  std::vector<std::vector<int>> spiralMatrixIII(
      int rows, int cols, int y, int x) {
    const int n{rows * cols};
    std::vector<std::vector<int>> output(n, std::vector<int>(2));

    output[0][0] = y;
    output[0][1] = x;
    int i{1};

    int maxX{x}, maxY{y}, minX{x}, minY{y};
    while (i < n) {
      maxX += 1;
      if (y >= 0) {
        for (++x; x <= maxX && x < cols; ++x, ++i) {
          output[i][0] = y;
          output[i][1] = x;
        }
      } else {
        y = -1;
      }
      x = maxX;

      if (i >= n) break;

      maxY += 1;
      if (x < cols) {
        for (++y; y <= maxY && y < rows; ++y, ++i) {
          output[i][0] = y;
          output[i][1] = x;
        }
      } else {
        x = cols;
      }
      y = maxY;

      if (i >= n) break;

      minX -= 1;
      if (y < rows) {
        for (--x; x >= minX && x >= 0; --x, ++i) {
          output[i][0] = y;
          output[i][1] = x;
        }
      } else {
        y = rows;
      }
      x = minX;

      if (i >= n) break;

      minY -= 1;
      if (x >= 0) {
        for (--y; y >= minY && y >= 0; --y, ++i) {
          output[i][0] = y;
          output[i][1] = x;
        }
      } else {
        x = -1;
      }
      y = minY;
    }

    return output;
  }
};
