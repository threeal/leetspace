#include <stdlib.h>

int** restoreMatrix(
    int* rowSum, int rowSumSize,
    int* colSum, int colSumSize,
    int* returnSize, int** returnColumnSizes) {
  (void)rowSum;
  (void)colSum;

  *returnSize = rowSumSize;
  int** returnData = malloc(rowSumSize * sizeof(int*));
  *returnColumnSizes = malloc(rowSumSize * sizeof(int));
  for (int i = colSumSize - 1; i >= 0; --i) {
    returnData[i] = malloc(colSumSize * sizeof(int));
    (*returnColumnSizes)[i] = colSumSize;
  }

  return returnData;
}
