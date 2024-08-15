#include <stdlib.h>

int** spiralMatrixIII(
    int rows, int cols, int y, int x,
    int* returnSize, int** returnColumnSizes) {
  *returnSize = rows * cols;
  *returnColumnSizes = malloc(*returnSize * sizeof(int));
  int** output = malloc(*returnSize * sizeof(int*));
  for (int i = *returnSize - 1; i >= 0; --i) {
    (*returnColumnSizes)[i] = 2;
    output[i] = malloc(2 * sizeof(int));
  }

  output[0][0] = y;
  output[0][1] = x;
  int i = 1;

  int maxX = x, maxY = y, minX = x, minY = y;
  while (i < *returnSize) {
    maxX += 1;
    if (y >= 0) {
      for (++x; x <= maxX && x < cols; ++x, ++i) {
        output[i][0] = y;
        output[i][1] = x;
      }
    } else {
      y = -1;
    }
    x = maxX;

    if (i >= *returnSize) break;

    maxY += 1;
    if (x < cols) {
      for (++y; y <= maxY && y < rows; ++y, ++i) {
        output[i][0] = y;
        output[i][1] = x;
      }
    } else {
      x = cols;
    }
    y = maxY;

    if (i >= *returnSize) break;

    minX -= 1;
    if (y < rows) {
      for (--x; x >= minX && x >= 0; --x, ++i) {
        output[i][0] = y;
        output[i][1] = x;
      }
    } else {
      y = rows;
    }
    x = minX;

    if (i >= *returnSize) break;

    minY -= 1;
    if (x >= 0) {
      for (--y; y >= minY && y >= 0; --y, ++i) {
        output[i][0] = y;
        output[i][1] = x;
      }
    } else {
      x = -1;
    }
    y = minY;
  }

  return output;
}
