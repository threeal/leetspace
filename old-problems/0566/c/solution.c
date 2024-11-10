#include <stdlib.h>

int** matrixReshape(
    int** mat, int matSize, int* matColSize, int r, int c,
    int* returnSize, int** returnColumnSizes) {
  const int matR = matSize;
  const int matC = matColSize[0];
  if (matR * matC != r * c) {
    *returnSize = matSize;
    *returnColumnSizes = matColSize;
    return mat;
  }

  int* data = malloc(r * c * sizeof(int));

  int** out = malloc(r * sizeof(int**));
  *returnSize = r;
  *returnColumnSizes = malloc(r * sizeof(int));
  for (int i = 0; i < r; ++i) {
    out[i] = data + i * c;
    (*returnColumnSizes)[i] = c;
  }

  int matY = 0, matX = 0, y = 0, x = 0;
  while (y < r) {
    out[y][x] = mat[matY][matX];
    if (++x >= c) ++y, x = 0;
    if (++matX >= matC) ++matY, matX = 0;
  }

  return out;
}
