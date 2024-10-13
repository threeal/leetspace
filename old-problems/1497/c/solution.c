#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

bool canArrange(int* arr, int arrSize, int k) {
  int* mod = malloc(k * sizeof(int));
  memset(mod, 0, k * sizeof(int));

  for (int i = 0; i < arrSize; ++i) {
    ++mod[((arr[i] % k) + k) % k];
  }

  if (mod[0] % 2 != 0) return false;
  if (k % 2 == 0 && mod[k / 2] % 2 != 0) return false;

  for (int i = 1; i < k - i; ++i) {
    if (mod[i] != mod[k - i]) return false;
  }

  return true;
}
