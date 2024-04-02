#include <stdlib.h>

int numSpecial(int** mat, int matSize, int* matColSize) {
  int* rows = malloc(matSize * sizeof(int));
  for (int i = 0; i < matSize; ++i) {
    rows[i] = -1;
  }

  int* cols = malloc(matColSize[0] * sizeof(int));
  for (int i = 0; i < matColSize[0]; ++i) {
    cols[i] = -1;
  }

  for (int i = 0; i < matSize; ++i) {
    for (int j = 0; j < matColSize[i]; ++j) {
      if (mat[i][j] == 1) {
        rows[i] = rows[i] == -1 ? j : -2;
        cols[j] = cols[j] == -1 ? i : -2;
      }
    }
  }

  int specials = 0;
  for (int i = 0; i < matSize; ++i) {
    if (rows[i] >= 0 && cols[rows[i]] == i) ++specials;
  }

  free(rows);
  free(cols);

  return specials;
}
