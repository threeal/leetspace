#include <stdlib.h>

int** construct2DArray(
    int* original, int originalSize, int m, int n,
    int* returnSize, int** returnColumnSizes) {
  if (originalSize != m * n) {
    *returnSize = 0;
    *returnColumnSizes = NULL;
    return NULL;
  }

  int** output = malloc(m * sizeof(int*));

  *returnSize = m;
  *returnColumnSizes = malloc(m * sizeof(int));

  for (int i = m - 1; i >= 0; --i) {
    output[i] = original + i * n;
    (*returnColumnSizes)[i] = n;
  }

  return output;
}
