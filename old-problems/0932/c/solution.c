#include <stdlib.h>

int* beautifulArray(int n, int* returnSize) {
  int* res = malloc(n * sizeof(int));
  int resSize = 0;
  res[resSize++] = 1;

  int* prev = malloc(n * sizeof(int));
  int prevSize = 0;

  for (int i = 2; i <= n; ++i) {
    int* temp = res;
    res = prev;
    prev = temp;

    prevSize = resSize;
    resSize = 0;

    for (int j = 0; j < prevSize; ++j) {
      if (prev[j] * 2 - 1 <= i) res[resSize++] = prev[j] * 2 - 1;
    }

    for (int j = 0; j < prevSize; ++j) {
      if (prev[j] * 2 <= i) res[resSize++] = prev[j] * 2;
    }
  }

  *returnSize = resSize;
  return res;
}
