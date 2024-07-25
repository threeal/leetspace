#include <stdlib.h>

int** restoreMatrix(
    int* rowSum, int rowSumSize,
    int* colSum, int colSumSize,
    int* returnSize, int** returnColumnSizes) {
  *returnSize = rowSumSize;
  int** returnData = malloc(rowSumSize * sizeof(int*));
  *returnColumnSizes = malloc(rowSumSize * sizeof(int));
  for (int i = rowSumSize - 1; i >= 0; --i) {
    returnData[i] = calloc(colSumSize, sizeof(int));
    (*returnColumnSizes)[i] = colSumSize;
  }

  int row = rowSumSize - 1;
  int col = colSumSize - 1;
  while (row >= 0 && col >= 0) {
    if (rowSum[row] == colSum[col]) {
      returnData[row][col] = rowSum[row];
      --row;
      --col;
    } else if (rowSum[row] < colSum[col]) {
      returnData[row][col] = rowSum[row];
      colSum[col] -= rowSum[row];
      --row;
    } else {
      returnData[row][col] = colSum[col];
      rowSum[row] -= colSum[col];
      --col;
    }
  }

  return returnData;
}
