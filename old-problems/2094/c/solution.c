#include <stdlib.h>

static int* output;
static int outputSize;
static int outputMaxSize = 0;

int* findEvenNumbers(int* digits, int digitsSize, int* returnSize) {
  outputSize = 0;

  int freqs[10] = {0};
  for (int i = 0; i < digitsSize; ++i) ++freqs[digits[i]];

  for (int i = 1; i < 10; ++i) {
    if (freqs[i] == 0) continue;
    --freqs[i];
    for (int j = 0; j < 10; ++j) {
      if (freqs[j] == 0) continue;
      --freqs[j];
      for (int k = 0; k < 10; k += 2) {
        if (freqs[k] == 0) continue;
        if (outputSize == outputMaxSize) {
          if (outputMaxSize == 0) {
            outputMaxSize = 32;
            output = malloc(outputMaxSize * sizeof(int));
          } else {
            outputMaxSize *= 32;
            output = realloc(output, outputMaxSize * sizeof(int));
          }
        }
        output[outputSize++] = i * 100 + j * 10 + k;
      }
      ++freqs[j];
    }
    ++freqs[i];
  }

  *returnSize = outputSize;
  return output;
}
