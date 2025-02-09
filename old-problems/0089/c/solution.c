#include <stdlib.h>

int* grayCode(int n, int* returnSize) {
  int* output = malloc((1 << n) * sizeof(int));
  output[0] = 0;
  output[1] = 1;

  for (int i = 1; i < n; ++i) {
    for (int l = (1 << i) - 1, r = 1 << i; l >= 0; --l, ++r) {
      output[r] = (1 << i) | output[l];
    }
  }

  *returnSize = 1 << n;
  return output;
}
