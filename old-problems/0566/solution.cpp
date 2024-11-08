#include <vector>

class Solution {
 public:
  std::vector<std::vector<int>> matrixReshape(
      std::vector<std::vector<int>>& mat, int r, int c) {
    int matR = mat.size();
    int matC = mat.front().size();
    if (matR * matC != r * c) return mat;

    std::vector<std::vector<int>> out(r, std::vector<int>(c));
    int matY{0}, matX{0}, y{0}, x{0};
    while (y < r) {
      out[y][x] = mat[matY][matX];
      if (++x >= c) ++y, x = 0;
      if (++matX >= matC) ++matY, matX = 0;
    }

    return out;
  }
};
