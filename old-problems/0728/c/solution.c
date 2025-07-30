#include <stdbool.h>
#include <stdlib.h>

int* selfDividingNumbers(int left, int right, int* returnSize) {
  static int* output = NULL;
  if (output == NULL) output = malloc(339 * sizeof(int));

  int outputSize = 0;
  for (int num = left; num <= right; ++num) {
    bool valid = true;
    for (int exp = 1; exp <= num; exp *= 10) {
      const int digit = num / exp % 10;
      if (digit == 0 || num % digit != 0) {
        valid = false;
        break;
      }
    }
    if (valid) output[outputSize++] = num;
  }

  *returnSize = outputSize;
  return output;
}
