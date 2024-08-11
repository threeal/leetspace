#include <stdlib.h>
#include <string.h>

int* decrypt(int* code, int codeSize, int k, int* returnSize) {
  int* output = malloc(codeSize * sizeof(int));
  *returnSize = codeSize;

  if (k > 0) {
    int sum = 0;
    for (int i = 0; i < k; ++i) sum += code[i];

    for (int l = 0, r = k; r < codeSize; ++l, ++r) {
      sum -= code[l];
      sum += code[r];
      output[l] = sum;
    }

    for (int l = codeSize - k, r = 0; l < codeSize; ++l, ++r) {
      sum -= code[l];
      sum += code[r];
      output[l] = sum;
    }
  } else if (k < 0) {
    int sum = 0;
    for (int i = codeSize + k; i < codeSize; ++i) sum += code[i];

    for (int l = codeSize + k - 1, r = codeSize - 1; l >= 0; --l, --r) {
      sum += code[l];
      sum -= code[r];
      output[r] = sum;
    }

    for (int l = codeSize - 1, r = -k - 1; r >= 0; --l, --r) {
      sum += code[l];
      sum -= code[r];
      output[r] = sum;
    }
  } else {
    memset(output, 0, codeSize * sizeof(int));
  }

  return output;
}
