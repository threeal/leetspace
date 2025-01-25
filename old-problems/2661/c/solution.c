#include <stdlib.h>

int firstCompleteIndex(
    int* arr, int arrSize, int** mat, int matSize, int* matColSize) {
  int* arrPos = malloc((arrSize + 1) * sizeof(int));
  for (int i = 0; i < arrSize; ++i) {
    arrPos[arr[i]] = i;
  }

  int minPos = arrSize - 1;

  for (int i = 0; i < matSize; ++i) {
    int maxPos = 0;
    for (int j = 0; j < matColSize[i]; ++j) {
      if (arrPos[mat[i][j]] > maxPos) maxPos = arrPos[mat[i][j]];
      if (maxPos >= minPos) break;
    }

    if (maxPos < minPos) minPos = maxPos;
  }

  for (int j = 0; j < matColSize[0]; ++j) {
    int maxPos = 0;
    for (int i = 0; i < matSize; ++i) {
      if (arrPos[mat[i][j]] > maxPos) maxPos = arrPos[mat[i][j]];
      if (maxPos >= minPos) break;
    }

    if (maxPos < minPos) minPos = maxPos;
  }

  return minPos;
}
