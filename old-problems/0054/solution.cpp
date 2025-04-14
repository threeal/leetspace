#include <vector>

class Solution {
 public:
  std::vector<int> spiralOrder(std::vector<std::vector<int>>& matrix) {
    const int sy = matrix.size();
    const int sx = matrix[0].size();

    std::vector<int> output(sy * sx);
    int i{-1}, ly{0}, lx{-1}, hy{sy - 1}, hx{sx - 1};
    while (++lx <= hx) {
      for (int x{lx}; x <= hx; ++x) output[++i] = matrix[ly][x];

      if (++ly > hy) break;
      for (int y{ly}; y <= hy; ++y) output[++i] = matrix[y][hx];

      if (--hx < lx) break;
      for (int x{hx}; x >= lx; --x) output[++i] = matrix[hy][x];

      if (--hy < ly) break;
      for (int y{hy}; y >= ly; --y) output[++i] = matrix[y][lx];
    }

    return output;
  }
};
