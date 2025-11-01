#include <stdlib.h>

int findSmallestInteger(int* nums, int numsSize, int value) {
  int* freqs = malloc(value * sizeof(int));
  for (int i = 0; i < value; ++i) freqs[i] = 0;

  for (int i = 0; i < numsSize; ++i) {
    ++freqs[(value + (nums[i] % value)) % value];
  }

  int candidate = 0;
  for (int i = 1; i < value; ++i) {
    if (freqs[i] < freqs[candidate]) candidate = i;
  }

  return value * freqs[candidate] + candidate;
}
