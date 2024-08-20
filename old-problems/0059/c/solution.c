#include <stdlib.h>

int** generateMatrix(int n, int* returnSize, int** returnColumnSizes) {
  *returnSize = n;
  *returnColumnSizes = malloc(*returnSize * sizeof(int));
  int** output = malloc(*returnSize * sizeof(int*));
  for (int i = n - 1; i >= 0; --i) {
    (*returnColumnSizes)[i] = n;
    output[i] = malloc((*returnColumnSizes)[i] * sizeof(int));
  }
  return output;
}
