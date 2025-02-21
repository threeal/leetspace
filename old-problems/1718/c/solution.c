#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

static bool construct(
    int n, bool* exists, int* output, const int outputSize, int pos);

int* constructDistancedSequence(int n, int* returnSize) {
  bool* exists = malloc((n + 1) * sizeof(bool));
  memset(exists, false, (n + 1) * sizeof(bool));

  const int outputSize = n * 2 - 1;
  int* output = malloc(outputSize * sizeof(int));
  memset(output, 0, outputSize * sizeof(int));

  construct(n, exists, output, outputSize, 0);

  free(exists);

  *returnSize = outputSize;
  return output;
}

static bool construct(
    int n, bool* exists, int* output, const int outputSize, int pos) {
  while (pos < outputSize && output[pos] != 0) ++pos;

  if (pos == outputSize) return true;

  for (int i = n; i >= 2; --i) {
    if (exists[i]) continue;
    if (pos + i >= outputSize) return false;
    if (output[pos + i] != 0) continue;

    exists[i] = true;
    output[pos] = i;
    output[pos + i] = i;

    if (construct(n, exists, output, outputSize, pos + 1)) return true;

    exists[i] = false;
    output[pos] = 0;
    output[pos + i] = 0;
  }

  if (!exists[1]) {
    exists[1] = true;
    output[pos] = 1;

    if (construct(n, exists, output, outputSize, pos + 1)) return true;

    exists[1] = false;
    output[pos] = 0;
  }

  return false;
}
