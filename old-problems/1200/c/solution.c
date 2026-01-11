#include <stdlib.h>

int compare(const void* a, const void* b) {
  return *(int*)a - *(int*)b;
}

int** minimumAbsDifference(
    int* arr, int arrSize, int* returnSize, int** returnColumnSizes) {
  qsort(arr, arrSize, sizeof(int), compare);

  int minDiff = arr[1] - arr[0];
  int minDiffCount = 1;

  for (int i = 2; i < arrSize; ++i) {
    const int diff = arr[i] - arr[i - 1];
    if (diff > minDiff) continue;
    if (diff < minDiff) {
      minDiff = diff;
      minDiffCount = 1;
    } else {
      ++minDiffCount;
    }
  }

  int** output = malloc(minDiffCount * sizeof(int*));
  int* outputColSizes = malloc(minDiffCount * sizeof(int));
  int outputSize = 0;

  for (int i = 1; i < arrSize; ++i) {
    if (arr[i] - arr[i - 1] == minDiff) {
      output[outputSize] = malloc(2 * sizeof(int));
      output[outputSize][0] = arr[i - 1];
      output[outputSize][1] = arr[i];
      outputColSizes[outputSize] = 2;
      ++outputSize;
    }
  }

  *returnSize = outputSize;
  *returnColumnSizes = outputColSizes;
  return output;
}
