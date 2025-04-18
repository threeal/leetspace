#include <stdlib.h>
#include <string.h>

static void permute(int*** it, int* freqs, int* nums, int numsSize, int i);

int** permuteUnique(
    int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
  int n = 1, totalFreq = 0, freqs[21] = {0};
  for (int i = 0; i < numsSize; ++i) {
    n *= ++totalFreq;
    n /= ++freqs[nums[i] + 10];
  }

  *returnSize = n;
  *returnColumnSizes = malloc(n * sizeof(int));
  int** output = malloc(n * sizeof(int*));
  for (int i = 0; i < n; ++i) {
    (*returnColumnSizes)[i] = numsSize;
    output[i] = malloc(numsSize * sizeof(int));
  }

  int** it = output;
  permute(&it, freqs, nums, numsSize, 0);

  return output;
}

static void permute(int*** it, int* freqs, int* nums, int numsSize, int i) {
  if (i + 1 == numsSize) {
    for (int j = 0; j < 21; ++j) {
      if (freqs[j] != 0) {
        nums[i] = j - 10;
        memcpy(**it, nums, numsSize * sizeof(int));
        ++(*it);
      }
    }
  } else {
    for (int j = 0; j < 21; ++j) {
      if (freqs[j] != 0) {
        --freqs[j];
        nums[i] = j - 10;
        permute(it, freqs, nums, numsSize, i + 1);
        ++freqs[j];
      }
    }
  }
}
