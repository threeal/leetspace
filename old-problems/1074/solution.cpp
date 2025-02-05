#include <vector>

class Solution {
 public:
  int numSubmatrixSumTarget(std::vector<std::vector<int>>& matrix, int target) {
    int count{0};
    for (std::size_t i{0}; i < matrix.size(); ++i) {
      for (std::size_t j{0}; j < matrix[i].size(); ++j) {
        if (matrix[i][j] == target) ++count;
      }
    }

    std::vector<std::vector<int>> hSum{matrix}, vSum{matrix};
    for (std::size_t i{0}; i < hSum.size(); ++i) {
      for (std::size_t j{0}; j < vSum[i].size(); ++j) {
        for (std::size_t ii{i}; ii < vSum.size(); ++ii) {
          for (std::size_t jj{vSum[ii].size() - 1}; jj > j; --jj) {
            vSum[ii][jj] = hSum[ii][jj] + vSum[ii][jj - 1];
            if (vSum[ii][jj] == target) ++count;
          }
        }
      }

      for (std::size_t ii{hSum.size() - 1}; ii > i; --ii) {
        for (std::size_t jj{0}; jj < hSum[ii].size(); ++jj) {
          hSum[ii][jj] = matrix[ii][jj] + hSum[ii - 1][jj];
          if (hSum[ii][jj] == target) ++count;
        }
        vSum[ii].assign(hSum[ii].begin(), hSum[ii].end());
      }
    }

    return count;
  }
};
