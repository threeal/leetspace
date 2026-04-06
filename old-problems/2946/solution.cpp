#include <vector>

class Solution {
 public:
  bool areSimilar(std::vector<std::vector<int>>& mat, int k) {
    const std::size_t n{mat[0].size()};
    for (std::size_t i{0}; i < mat.size(); ++i) {
      for (std::size_t j{0}; j < n; ++j) {
        if (mat[i][j] != mat[i][(j + k) % n]) return false;
      }

      if (++i >= mat.size()) break;

      for (std::size_t j{0}; j < n; ++j) {
        if (mat[i][j] != mat[i][(n * k + j - k) % n]) return false;
      }
    }
    return true;
  }
};
