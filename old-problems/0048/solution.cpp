#include <vector>

class Solution {
 public:
  void rotate(std::vector<std::vector<int>>& matrix) {
    const std::size_t n{matrix.size()};
    for (std::size_t i{0}; i < n / 2; ++i) {
      for (std::size_t j{i}; j < n - i - 1; ++j) {
        const int temp{matrix[j][i]};
        matrix[j][i] = matrix[n - 1 - i][j];
        matrix[n - 1 - i][j] = matrix[n - 1 - j][n - 1 - i];
        matrix[n - 1 - j][n - 1 - i] = matrix[i][n - 1 - j];
        matrix[i][n - 1 - j] = temp;
      }
    }
  }
};
