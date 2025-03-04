#include <stdlib.h>

int compare(const void* a, const void* b) {
  return *(int*)a - *(int*)b;
}

int* intersection(int** nums, int numsSize, int* numsColSize, int* returnSize) {
  int freqs[10001] = {0};
  for (int i = numsSize - 1; i > 0; --i) {
    for (int j = 0; j < numsColSize[i]; ++j) ++freqs[nums[i][j]];
  }

  int* output = malloc(numsColSize[0] * sizeof(int));
  int outputSize = 0;
  for (int i = 0; i < numsColSize[0]; ++i) {
    if (++freqs[nums[0][i]] == numsSize) output[outputSize++] = nums[0][i];
  }

  qsort(output, outputSize, sizeof(int), compare);

  *returnSize = outputSize;
  return output;
}
