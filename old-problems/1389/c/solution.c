#include <stdlib.h>

int* createTargetArray(
    int* nums, int numsSize, int* index, int indexSize, int* returnSize) {
  (void)indexSize;

  int* output = malloc(numsSize * sizeof(int));
  int outputSize = 0;

  for (int i = 0; i < numsSize; ++i) {
    for (int j = outputSize; j > index[i]; --j) {
      output[j] = output[j - 1];
    }
    output[index[i]] = nums[i];
    ++outputSize;
  }

  *returnSize = outputSize;
  return output;
}
