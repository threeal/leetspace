#include <stdlib.h>

int* separateDigits(int* nums, int numsSize, int* returnSize) {
  int* output = malloc(6 * numsSize * sizeof(int));
  int outputSize = 0;

  for (int i = 0; i < numsSize; ++i) {
    for (int exp = 100000; exp > 0; exp /= 10) {
      if (exp <= nums[i]) output[outputSize++] = nums[i] / exp % 10;
    }
  }

  *returnSize = outputSize;
  return output;
}
