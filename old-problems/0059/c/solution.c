#include <stdlib.h>

int** generateMatrix(int n, int* returnSize, int** returnColumnSizes) {
  *returnSize = n;
  *returnColumnSizes = malloc(*returnSize * sizeof(int));
  int** output = malloc(*returnSize * sizeof(int*));
  for (int i = n - 1; i >= 0; --i) {
    (*returnColumnSizes)[i] = n;
    output[i] = malloc((*returnColumnSizes)[i] * sizeof(int));
  }

  int y = 0, x = -1, i = 0;
  for (int j = n; j > 0; --j) output[y][++x] = ++i;

  while (--n > 0) {
    for (int j = n; j > 0; --j) output[++y][x] = ++i;
    for (int j = n; j > 0; --j) output[y][--x] = ++i;

    if (--n <= 0) break;
    for (int j = n; j > 0; --j) output[--y][x] = ++i;
    for (int j = n; j > 0; --j) output[y][++x] = ++i;
  }

  return output;
}
