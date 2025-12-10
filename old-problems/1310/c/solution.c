#include <stdlib.h>

int* xorQueries(
    int* arr, int arrSize,
    int** queries, int queriesSize, int* queriesColSize, int* returnSize) {
  (void)queriesColSize;

  for (int i = 1; i < arrSize; ++i) arr[i] ^= arr[i - 1];

  int* output = malloc(queriesSize * sizeof(int));
  int outputSize = 0;

  for (int i = 0; i < queriesSize; ++i) {
    output[outputSize++] = queries[i][0] > 0
        ? arr[queries[i][1]] ^ arr[queries[i][0] - 1]
        : arr[queries[i][1]];
  }

  *returnSize = outputSize;
  return output;
}
