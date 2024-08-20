#include <vector>

class Solution {
 public:
  std::vector<std::vector<int>> generateMatrix(int n) {
    std::vector<std::vector<int>> output(n, std::vector<int>(n));

    int y{0}, x{-1}, i{0};
    for (int j{n}; j > 0; --j) output[y][++x] = ++i;

    while (--n > 0) {
      for (int j{n}; j > 0; --j) output[++y][x] = ++i;
      for (int j{n}; j > 0; --j) output[y][--x] = ++i;

      if (--n <= 0) break;
      for (int j{n}; j > 0; --j) output[--y][x] = ++i;
      for (int j{n}; j > 0; --j) output[y][++x] = ++i;
    }

    return output;
  }
};
