#include <stdlib.h>

int* gGroupSizes;
int compare(const void* a, const void* b) {
  return gGroupSizes[*(int*)a] - gGroupSizes[*(int*)b];
}

int** groupThePeople(
    int* groupSizes, int groupSizesSize,
    int* returnSize, int** returnColumnSizes) {
  int* indices = malloc(groupSizesSize * sizeof(int));
  for (int i = 0; i < groupSizesSize; ++i) indices[i] = i;

  gGroupSizes = groupSizes;
  qsort(indices, groupSizesSize, sizeof(int), compare);

  int** output = malloc(groupSizesSize * sizeof(int*));
  int* outputColSizes = malloc(groupSizesSize * sizeof(int));
  int outputSize = 0;

  int i = 0;
  while (i < groupSizesSize) {
    const int groupSize = groupSizes[indices[i]];
    int* arr = malloc(groupSize * sizeof(int));
    for (int j = 0; j < groupSize; ++j) {
      arr[j] = indices[i + j];
    }

    output[outputSize] = arr;
    outputColSizes[outputSize] = groupSize;
    ++outputSize;

    i += groupSize;
  }

  *returnSize = outputSize;
  *returnColumnSizes = outputColSizes;
  return output;
}
