#include <stdlib.h>

int* sumZero(int n, int* returnSize) {
  int* arr = malloc(n * sizeof(int));
  int arrSize = 0;

  for (int i = n / 2; i > 0; --i) {
    arr[arrSize++] = i;
    arr[arrSize++] = -i;
  }

  if (n % 2 != 0) arr[arrSize++] = 0;

  *returnSize = arrSize;
  return arr;
}
