#include <stdlib.h>

int* circularPermutation(int n, int start, int* returnSize) {
  const int outputSize = 1 << n;
  int* output = malloc(outputSize * sizeof(int));
  for (int i = 0; i < outputSize; ++i) {
    output[i] = i ^ (i >> 1) ^ start;
  }
  *returnSize = outputSize;
  return output;
}
