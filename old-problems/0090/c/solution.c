#include <string.h>

int outputBuff[10240];
int* output[1024];

int outputSize;
int outputColSize[1024];

int arr[10];
int arrSize;

static void findSubsetsWithDup(int* freqs, int i);

int** subsetsWithDup(
    int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
  int freqs[21] = {0};
  for (int i = 0; i < numsSize; ++i) {
    ++freqs[nums[i] + 10];
  }

  outputSize = 0;
  arrSize = 0;

  findSubsetsWithDup(freqs, 0);

  *returnSize = outputSize;
  *returnColumnSizes = outputColSize;
  return output;
}

static void findSubsetsWithDup(int* freqs, int i) {
  if (i == 20) {
    output[outputSize] = outputBuff + (outputSize * 10);
    outputColSize[outputSize] = arrSize;
    memcpy(output[outputSize++], arr, arrSize * sizeof(int));

    for (int j = 0; j < freqs[i]; ++j) {
      arr[arrSize++] = i - 10;

      output[outputSize] = outputBuff + (outputSize * 10);
      outputColSize[outputSize] = arrSize;
      memcpy(output[outputSize++], arr, arrSize * sizeof(int));
    }
  } else {
    findSubsetsWithDup(freqs, i + 1);
    for (int j = 0; j < freqs[i]; ++j) {
      arr[arrSize++] = i - 10;
      findSubsetsWithDup(freqs, i + 1);
    }
  }

  arrSize -= freqs[i];
}
