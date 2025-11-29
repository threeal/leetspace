#include <stdlib.h>

int compare(const void* a, const void* b) {
  return (*(int**)a)[0] - (*(int**)b)[0];
}

int** mergeSimilarItems(
    int** items1, int items1Size, int* items1ColSize,
    int** items2, int items2Size, int* items2ColSize,
    int* returnSize, int** returnColumnSizes) {
  qsort(items1, items1Size, sizeof(int*), compare);
  qsort(items2, items2Size, sizeof(int*), compare);

  int** output = malloc((items1Size + items2Size) * sizeof(int*));
  int* outputColSize = malloc((items1Size + items2Size) * sizeof(int));
  int outputSize = 0;

  int i1 = 0, i2 = 0;
  while (i1 < items1Size && i2 < items2Size) {
    if (items1[i1][0] == items2[i2][0]) {
      output[outputSize] = malloc(2 * sizeof(int));
      output[outputSize][0] = items1[i1][0];
      output[outputSize][1] = items1[i1][1] + items2[i2][1];
      outputColSize[outputSize] = 2;
      ++outputSize;
      ++i1;
      ++i2;
    } else if (items1[i1][0] < items2[i2][0]) {
      output[outputSize] = items1[i1];
      outputColSize[outputSize] = items1ColSize[i1];
      ++outputSize;
      ++i1;
    } else {
      output[outputSize] = items2[i2];
      outputColSize[outputSize] = items2ColSize[i2];
      ++outputSize;
      ++i2;
    }
  }

  while (i1 < items1Size) {
    output[outputSize] = items1[i1];
    outputColSize[outputSize] = items1ColSize[i1];
    ++outputSize;
    ++i1;
  }

  while (i2 < items2Size) {
    output[outputSize] = items2[i2];
    outputColSize[outputSize] = items2ColSize[i2];
    ++outputSize;
    ++i2;
  }

  *returnSize = outputSize;
  *returnColumnSizes = outputColSize;
  return output;
}
