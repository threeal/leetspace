#include <stdlib.h>

int** specialGrid(int n, int* returnSize, int** returnColumnSizes) {
  int** output = malloc(n * sizeof(int*));
  int* outputColSize = malloc(n * sizeof(int));
  for (int i = 0; i < n; ++i) {
    output[i] = malloc(n * sizeof(int));
    outputColSize[i] = n;
  }

  *returnSize = n;
  *returnColumnSizes = outputColSize;
  return output;
}
