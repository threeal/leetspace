#include <vector>

class Solution {
 public:
  std::vector<std::vector<int>> modifiedMatrix(
      std::vector<std::vector<int>>& matrix) {
    for (std::size_t i{0}; i < matrix[0].size(); ++i) {
      int maxValue{0};
      for (std::size_t j{0}; j < matrix.size(); ++j) {
        if (matrix[j][i] > maxValue) maxValue = matrix[j][i];
      }

      for (std::size_t j{0}; j < matrix.size(); ++j) {
        if (matrix[j][i] == -1) matrix[j][i] = maxValue;
      }
    }
    return matrix;
  }
};
