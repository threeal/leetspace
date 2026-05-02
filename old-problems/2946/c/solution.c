#include <stdbool.h>

bool areSimilar(int** mat, int matSize, int* matColSize, int k) {
  const int n = matColSize[0];
  for (int i = 0; i < matSize; ++i) {
    for (int j = 0; j < n; ++j) {
      if (mat[i][j] != mat[i][(j + k) % n]) return false;
    }

    if (++i >= matSize) break;

    for (int j = 0; j < n; ++j) {
      if (mat[i][j] != mat[i][(n * k + j - k) % n]) return false;
    }
  }
  return true;
}
