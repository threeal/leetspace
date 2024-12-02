#include <stdlib.h>

char** rotateTheBox(
    char** boxGrid, int boxGridSize, int* boxGridColSize,
    int* returnSize, int** returnColumnSizes) {
  const int m = boxGridSize;
  const int n = boxGridColSize[0];

  *returnSize = n;
  *returnColumnSizes = malloc(n * sizeof(int));
  char** out = malloc(n * sizeof(char**));
  for (int i = 0; i < n; ++i) {
    (*returnColumnSizes)[i] = m;
    out[i] = malloc(m * sizeof(char));
  }

  for (int i = 0; i < m; ++i) {
    for (int j = n - 1, jj = n - 1; j >= 0; --j) {
      switch (boxGrid[m - i - 1][j]) {
        case '#':
          out[j][i] = '.';
          out[jj][i] = '#';
          --jj;
          break;

        case '*':
          out[j][i] = '*';
          jj = j - 1;
          break;

        case '.':
          out[j][i] = '.';
      }
    }
  }

  return out;
}
