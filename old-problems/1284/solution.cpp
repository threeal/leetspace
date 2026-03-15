#include <vector>

class Solution {
 public:
  int minFlips(std::vector<std::vector<int>>& mat) {
    const int flips{explore(mat, 0, 0)};
    return flips < 1000 ? flips : -1;
  }

  int explore(
      std::vector<std::vector<int>>& mat, std::size_t i, std::size_t j) {
    if (i == mat.size()) {
      for (std::size_t i{0}; i < mat.size(); ++i) {
        for (std::size_t j{0}; j < mat[i].size(); ++j) {
          if (mat[i][j] == 1) return 1000;
        }
      }
      return 0;
    } else if (j == mat[i].size()) {
      return explore(mat, i + 1, 0);
    } else {
      const int noFlip{explore(mat, i, j + 1)};

      mat[i][j] = mat[i][j] == 0 ? 1 : 0;
      if (i > 0) mat[i - 1][j] = mat[i - 1][j] == 0 ? 1 : 0;
      if (i + 1 < mat.size()) mat[i + 1][j] = mat[i + 1][j] == 0 ? 1 : 0;
      if (j > 0) mat[i][j - 1] = mat[i][j - 1] == 0 ? 1 : 0;
      if (j + 1 < mat[i].size()) mat[i][j + 1] = mat[i][j + 1] == 0 ? 1 : 0;

      const int withFlip{1 + explore(mat, i, j + 1)};

      mat[i][j] = mat[i][j] == 0 ? 1 : 0;
      if (i > 0) mat[i - 1][j] = mat[i - 1][j] == 0 ? 1 : 0;
      if (i + 1 < mat.size()) mat[i + 1][j] = mat[i + 1][j] == 0 ? 1 : 0;
      if (j > 0) mat[i][j - 1] = mat[i][j - 1] == 0 ? 1 : 0;
      if (j + 1 < mat[i].size()) mat[i][j + 1] = mat[i][j + 1] == 0 ? 1 : 0;

      return noFlip < withFlip ? noFlip : withFlip;
    }
  }
};
