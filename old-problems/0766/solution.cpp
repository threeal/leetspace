#include <vector>

class Solution {
 public:
  bool isToeplitzMatrix(std::vector<std::vector<int>>& matrix) {
    for (std::size_t i{0}; i < matrix.size(); ++i) {
      std::size_t ii{i + 1}, jj{1};
      while (ii < matrix.size() && jj < matrix[ii].size()) {
        if (matrix[ii][jj] != matrix[i][0]) return false;
        ++ii, ++jj;
      }
    }

    for (std::size_t j{1}; j < matrix[0].size(); ++j) {
      std::size_t ii{1}, jj{j + 1};
      while (ii < matrix.size() && jj < matrix[ii].size()) {
        if (matrix[ii][jj] != matrix[0][j]) return false;
        ++ii, ++jj;
      }
    }

    return true;
  }
};
