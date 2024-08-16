#include <algorithm>
#include <vector>

class Solution {
 public:
  int largestMagicSquare(std::vector<std::vector<int>>& grid) {
    const int m = grid.size();
    const int n = grid.front().size();

    std::vector<std::vector<int>> hSum(m, std::vector<int>(n + 1));
    for (int i{m - 1}; i >= 0; --i) {
      hSum[i][n] = 0;
      for (int j{n - 1}; j >= 0; --j) {
        hSum[i][j] = grid[i][j] + hSum[i][j + 1];
      }
    }

    std::vector<std::vector<int>> vSum(m + 1, std::vector<int>(n));
    for (int j{n - 1}; j >= 0; --j) {
      vSum[m][j] = 0;
      for (int i{m - 1}; i >= 0; --i) {
        vSum[i][j] = grid[i][j] + vSum[i + 1][j];
      }
    }

    for (int k{std::min(m, n)}; k > 1; --k) {
      for (int i{m - k}; i >= 0; --i) {
        for (int j{n - k}; j >= 0; --j) {
          int sum1{0};
          for (int kk{k - 1}; kk >= 0; --kk) {
            sum1 += grid[i + kk][j + kk];
          }

          int sum2{0};
          for (int ii{i + k - 1}, jj{j}; ii >= i; --ii, ++jj) {
            sum2 += grid[ii][jj];
          }

          if (sum1 != sum2) continue;

          bool pass{true};
          for (int ii{i + k - 1}; ii >= i; --ii) {
            if (hSum[ii][j] - hSum[ii][j + k] != sum1) {
              pass = false;
              break;
            }
          }
          if (!pass) continue;

          for (int jj{j + k - 1}; jj >= j; --jj) {
            if (vSum[i][jj] - vSum[i + k][jj] != sum1) {
              pass = false;
              break;
            }
          }
          if (!pass) continue;

          return k;
        }
      }
    }

    return 1;
  }
};
