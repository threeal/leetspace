#include <stdlib.h>

int* plusOne(int* digits, int digitsSize, int* returnSize) {
  int i = digitsSize - 1;
  ++digits[i];

  while (i > 0 && digits[i] >= 10) {
    ++digits[i - 1];
    digits[i] %= 10;
    --i;
  }

  if (digits[i] >= 10) {
    ++digitsSize;
    digits = realloc(digits, digitsSize * sizeof(int));
    for (int j = digitsSize - 1; j > 0; --j) {
      digits[j] = digits[j - 1];
    }
    digits[0] = 1;
    digits[1] %= 10;
  }

  *returnSize = digitsSize;
  return digits;
}
