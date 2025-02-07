#include <cstdlib>
#include <cstring>
#include <vector>

class Solution {
 public:
  void setZeroes(std::vector<std::vector<int>>& matrix) {
    for (std::size_t i{0}; i < matrix.size(); ++i) {
      for (std::size_t j{0}; j < matrix[i].size(); ++j) {
        if (matrix[i][j] != 0) continue;

        for (std::size_t k{i}; k < matrix.size(); ++k) {
          for (std::size_t l{0}; l < matrix[k].size(); ++l) {
            if (matrix[k][l] == 0) {
              matrix[i][l] = 0;
              matrix[k][j] = 0;
            }
          }
        }

        for (std::size_t k{i + 1}; k < matrix.size(); ++k) {
          if (matrix[k][j] == 0) {
            std::memset(matrix[k].data(), 0, matrix[k].size() * sizeof(int));
          }
        }

        for (std::size_t l{0}; l < matrix[i].size(); ++l) {
          if (matrix[i][l] == 0) {
            for (std::size_t k{0}; k < matrix.size(); ++k) {
              matrix[k][l] = 0;
            }
          }
        }

        std::memset(matrix[i].data(), 0, matrix[i].size() * sizeof(int));
        for (std::size_t k{0}; k < matrix.size(); ++k) {
          matrix[k][j] = 0;
        }

        return;
      }
    }
  }
};
