#include <stdlib.h>

int compare(const void* a, const void* b) {
  return *(int*)a - *(int*)b;
}

double trimMean(int* arr, int arrSize) {
  qsort(arr, arrSize, sizeof(int), compare);

  const int fifth = arrSize / 20;
  const int ninetyFifth = arrSize - fifth;

  int sum = 0;
  for (int i = fifth; i < ninetyFifth; ++i) {
    sum += arr[i];
  }

  return (double)sum / (ninetyFifth - fifth);
}
