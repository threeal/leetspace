#include <algorithm>
#include <vector>

class Solution {
 public:
  int countSquares(std::vector<std::vector<int>>& matrix) {
    int count{0};
    for (const auto val : matrix[0]) count += val;

    for (std::size_t i{1}; i < matrix.size(); ++i) {
      count += matrix[i][0];
      for (std::size_t j{1}; j < matrix[i].size(); ++j) {
        if (matrix[i][j] == 0) continue;
        matrix[i][j] += std::min(
            matrix[i - 1][j], std::min(matrix[i - 1][j - 1], matrix[i][j - 1]));
        count += matrix[i][j];
      }
    }

    return count;
  }
};
