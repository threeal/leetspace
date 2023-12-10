#include <vector>

class Solution {
 public:
  std::vector<std::vector<int>> transpose(std::vector<std::vector<int>>& matrix) {
    const auto m = matrix.size();
    const auto n = matrix[0].size();

    auto output = std::vector(n, std::vector<int>(m));
    for (std::size_t i = 0; i < m; ++i) {
      for (std::size_t j = 0; j < n; ++j) {
        output[j][i] = matrix[i][j];
      }
    }

    return output;
  }
};
