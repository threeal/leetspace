#include <stdlib.h>

int compare(const void* a, const void* b) {
  return *(int*)b - *(int*)a;
}

int findLucky(int* arr, int arrSize) {
  qsort(arr, arrSize, sizeof(int), compare);

  int l = 0;
  for (int r = 1; r < arrSize; ++r) {
    if (arr[r] != arr[r - 1]) {
      if (r - l == arr[r - 1]) return arr[r - 1];
      l = r;
    }
  }

  return (arrSize - l == arr[arrSize - 1]) ? arr[arrSize - 1] : -1;
}
