#include <stdbool.h>

static bool checkSideLength(
    int** mat, int matSize, int* matColSize, int threshold, int n);

int maxSideLength(int** mat, int matSize, int* matColSize, int threshold) {
  for (int i = 0; i < matSize; ++i) {
    for (int j = 1; j < matColSize[i]; ++j) {
      mat[i][j] += mat[i][j - 1];
    }
  }

  for (int i = 1; i < matSize; ++i) {
    for (int j = 0; j < matColSize[i]; ++j) {
      mat[i][j] += mat[i - 1][j];
    }
  }

  int low = 0, high = matSize < matColSize[0] ? matSize : matColSize[0];
  while (low < high) {
    const int mid = high - (high - low) / 2;
    if (mid == 0 || checkSideLength(mat, matSize, matColSize, threshold, mid)) {
      low = mid;
    } else {
      high = mid - 1;
    }
  }

  return low;
}

static bool checkSideLength(
    int** mat, int matSize, int* matColSize, int threshold, int n) {
  if (mat[n - 1][n - 1] <= threshold) return true;
  for (int i = n; i < matColSize[0]; ++i) {
    if (mat[n - 1][i] - mat[n - 1][i - n] <= threshold) return true;
  }

  for (int i = n; i < matSize; ++i) {
    if (mat[i][n - 1] - mat[i - n][n - 1] <= threshold) return true;
    for (int j = n; j < matColSize[i]; ++j) {
      const int sum =
          mat[i][j] - mat[i - n][j] - mat[i][j - n] + mat[i - n][j - n];
      if (sum <= threshold) return true;
    }
  }

  return false;
}
