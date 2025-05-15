#include <stdlib.h>

int* decompressRLElist(int* nums, int numsSize, int* returnSize) {
  int outputSize = 0;
  for (int i = 0; i < numsSize; i += 2) {
    outputSize += nums[i];
  }

  int* output = malloc(outputSize * sizeof(int));
  outputSize = 0;

  for (int i = 1; i < numsSize; i += 2) {
    for (int n = nums[i - 1]; n > 0; --n) {
      output[outputSize++] = nums[i];
    }
  }

  *returnSize = outputSize;
  return output;
}
