#include <stdlib.h>

int* getConcatenation(int* nums, int numsSize, int* returnSize) {
  int* output = malloc(numsSize * 2 * sizeof(int));
  for (int i = 0; i < numsSize; ++i) {
    output[i] = nums[i];
    output[numsSize + i] = nums[i];
  }
  *returnSize = numsSize * 2;
  return output;
}
