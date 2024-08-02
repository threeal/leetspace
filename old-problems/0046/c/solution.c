#include <stdlib.h>

int** fill(int** out, int i, int* nums, int numsSize);

int** permute(
    int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
  *returnSize = 1;
  for (int i = numsSize; i > 1; --i) *returnSize *= i;

  int** output = malloc(*returnSize * sizeof(int*));
  *returnColumnSizes = malloc(*returnSize * sizeof(int));
  for (int i = *returnSize - 1; i >= 0; --i) {
    output[i] = malloc(numsSize * sizeof(int));
    (*returnColumnSizes)[i] = numsSize;
  }

  fill(output, numsSize - 1, nums, numsSize);

  return output;
}

int** fill(int** out, int i, int* nums, int numsSize) {
  if (i == 0) {
    for (int j = numsSize - 1; j >= 0; --j) {
      if (nums[j] > 10) continue;
      (*out)[i] = nums[j];
      ++out;
    }
    return out;
  }

  for (int j = 0; j < numsSize; ++j) {
    if (nums[j] > 10) continue;

    nums[j] += 100;
    int** end = fill(out, i - 1, nums, numsSize);
    nums[j] -= 100;

    while (out != end) {
      (*out)[i] = nums[j];
      ++out;
    }
  }

  return out;
}
