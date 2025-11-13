#include <stdlib.h>

int* gFreqs;

int compare(const void* a, const void* b) {
  const int aa = *(int*)a;
  const int bb = *(int*)b;
  return gFreqs[aa] == gFreqs[bb] ? bb - aa : gFreqs[bb] - gFreqs[aa];
}

int* findXSum(int* nums, int numsSize, int k, int x, int* returnSize) {
  --k;

  int freqs[51] = {0};
  for (int i = 0; i < k; ++i) ++freqs[nums[i]];

  int indices[51];
  for (int i = 0; i < 51; ++i) indices[i] = i;

  const int outputSize = numsSize - k;
  int* output = malloc(outputSize * sizeof(int));
  for (int i = 0; i < outputSize; ++i) {
    ++freqs[nums[i + k]];

    gFreqs = freqs;
    qsort(indices, 51, sizeof(int), compare);

    int sum = 0;
    for (int i = 0; i < x; ++i) sum += indices[i] * freqs[indices[i]];
    output[i] = sum;

    --freqs[nums[i]];
  }

  *returnSize = outputSize;
  return output;
}
