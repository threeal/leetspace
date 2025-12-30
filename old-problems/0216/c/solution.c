#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void find(
    int* maxOutputSize, int*** output, int** outputColSizes, int* outputSize,
    int* nums, int* numsSize, int k, int n);

int** combinationSum3(int k, int n, int* returnSize, int** returnColumnSizes) {
  int maxOutputSize = 32;
  int** output = malloc(maxOutputSize * sizeof(int*));
  int* outputColSizes = malloc(maxOutputSize * sizeof(int));
  int outputSize = 0;

  int* nums = malloc(9 * sizeof(int));
  int numsSize = 0;

  const int max = n < 9 ? n : 9;
  for (int num = 1; num <= max; ++num) {
    nums[numsSize++] = num;
    find(&maxOutputSize, &output, &outputColSizes, &outputSize,
         nums, &numsSize, k - 1, n - num);

    --numsSize;
  }

  free(nums);

  *returnSize = outputSize;
  *returnColumnSizes = outputColSizes;
  return output;
}

static void find(
    int* maxOutputSize, int*** output, int** outputColSizes, int* outputSize,
    int* nums, int* numsSize, int k, int n) {
  if (k == 1) {
    if (n <= 9 && n > nums[*numsSize - 1]) {
      nums[(*numsSize)++] = n;

      if (*outputSize >= *maxOutputSize) {
        *maxOutputSize *= 4;
        *output = realloc(*output, *maxOutputSize * sizeof(int*));
        *outputColSizes = realloc(*outputColSizes, *maxOutputSize * sizeof(int));
      }

      (*output)[*outputSize] = malloc(*numsSize * sizeof(int));
      memcpy((*output)[*outputSize], nums, *numsSize * sizeof(int));
      (*outputColSizes)[(*outputSize)++] = *numsSize;

      --(*numsSize);
    }
  } else {
    const int max = n < 9 ? n : 9;
    for (int num = nums[*numsSize - 1] + 1; num <= max; ++num) {
      nums[(*numsSize)++] = num;
      find(maxOutputSize, output, outputColSizes, outputSize,
           nums, numsSize, k - 1, n - num);
      --(*numsSize);
    }
  }
}
