#include <stdlib.h>

static void reverse(int* arr, int arrSize) {
  for (int l = 0, r = arrSize - 1; l < r; ++l, --r) {
    const int temp = arr[l];
    arr[l] = arr[r];
    arr[r] = temp;
  }
}

int* pancakeSort(int* arr, int arrSize, int* returnSize) {
  int* output = malloc(arrSize * 2 * sizeof(int));
  int outputSize = 0;
  for (int n = arrSize; n > 0; --n) {
    int i = 0;
    while (arr[i] != n) ++i;
    if (i + 1 != n) {
      if (i != 0) {
        reverse(arr, i + 1);
        output[outputSize++] = i + 1;
      }

      reverse(arr, n);
      output[outputSize++] = n;
    }
  }
  *returnSize = outputSize;
  return output;
}
