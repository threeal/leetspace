#include <vector>

class Solution {
 public:
  std::vector<std::vector<int>> restoreMatrix(
      std::vector<int>& rowSum, std::vector<int>& colSum) {
    std::vector<std::vector<int>> mat(
        rowSum.size(), std::vector<int>(colSum.size(), 0));

    int row = rowSum.size() - 1;
    int col = colSum.size() - 1;
    while (row >= 0 && col >= 0) {
      if (rowSum[row] == colSum[col]) {
        mat[row][col] = rowSum[row];
        --row;
        --col;
      } else if (rowSum[row] < colSum[col]) {
        mat[row][col] = rowSum[row];
        colSum[col] -= rowSum[row];
        --row;
      } else {
        mat[row][col] = colSum[col];
        rowSum[row] -= colSum[col];
        --col;
      }
    }

    return mat;
  }
};
