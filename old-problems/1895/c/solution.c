#include <stdbool.h>
#include <stdlib.h>

int largestMagicSquare(int** grid, int gridSize, int* gridColSize) {
  const int m = gridSize;
  const int n = gridColSize[0];

  int** hSum = malloc(m * sizeof(int*));
  int** vSum = malloc((m + 1) * sizeof(int*));
  for (int i = m - 1; i >= 0; --i) {
    hSum[i] = malloc((n + 1) * sizeof(int));
    vSum[i] = malloc(n * sizeof(int));
  }
  vSum[m] = malloc(n * sizeof(int));

  for (int i = m - 1; i >= 0; --i) {
    hSum[i][n] = 0;
    for (int j = n - 1; j >= 0; --j) {
      hSum[i][j] = grid[i][j] + hSum[i][j + 1];
    }
  }

  for (int j = n - 1; j >= 0; --j) {
    vSum[m][j] = 0;
    for (int i = m - 1; i >= 0; --i) {
      vSum[i][j] = grid[i][j] + vSum[i + 1][j];
    }
  }

  for (int k = m < n ? m : n; k > 1; --k) {
    for (int i = m - k; i >= 0; --i) {
      for (int j = n - k; j >= 0; --j) {
        int sum1 = 0;
        for (int kk = k - 1; kk >= 0; --kk) {
          sum1 += grid[i + kk][j + kk];
        }

        int sum2 = 0;
        for (int ii = i + k - 1, jj = j; ii >= i; --ii, ++jj) {
          sum2 += grid[ii][jj];
        }

        if (sum1 != sum2) continue;

        bool pass = true;
        for (int ii = i + k - 1; ii >= i; --ii) {
          if (hSum[ii][j] - hSum[ii][j + k] != sum1) {
            pass = false;
            break;
          }
        }
        if (!pass) continue;

        for (int jj = j + k - 1; jj >= j; --jj) {
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

  free(vSum[m]);
  for (int i = m - 1; i >= 0; --i) {
    free(hSum[i]);
    free(vSum[i]);
  }
  free(hSum);
  free(vSum);

  return 1;
}
