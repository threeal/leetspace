#include <vector>

class Solution {
 public:
  std::vector<std::vector<int>> matrixBlockSum(
      std::vector<std::vector<int>>& mat, int k) {
    const std::size_t kk = k;
    const std::size_t m{mat.size()};
    const std::size_t n{mat[0].size()};

    for (std::size_t i{0}; i < m; ++i) {
      for (std::size_t j{1}; j < n; ++j) {
        mat[i][j] += mat[i][j - 1];
      }
    }

    for (std::size_t j{0}; j < n; ++j) {
      for (std::size_t i{1}; i < m; ++i) {
        mat[i][j] += mat[i - 1][j];
      }
    }

    std::vector<std::vector<int>> output(
        mat.size(), std::vector(mat[0].size(), 0));

    for (std::size_t i{0}; i < mat.size(); ++i) {
      for (std::size_t j{0}; j < mat[i].size(); ++j) {
        const std::size_t i1{std::min(i + kk, m - 1)};
        const std::size_t j1{std::min(j + kk, n - 1)};
        if (i > kk) {
          if (j > kk) {
            output[i][j] = mat[i1][j1] + mat[i - kk - 1][j - kk - 1] -
                mat[i - kk - 1][j1] - mat[i1][j - kk - 1];
          } else {
            output[i][j] = mat[i1][j1] - mat[i - kk - 1][j1];
          }
        } else {
          if (j > kk) {
            output[i][j] = mat[i1][j1] - mat[i1][j - kk - 1];
          } else {
            output[i][j] = mat[i1][j1];
          }
        }
      }
    }

    return output;
  }
};
