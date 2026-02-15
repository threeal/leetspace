#include <stdlib.h>

int compare(const void* a, const void* b) {
  return *(int*)b - *(int*)a;
}

int minSetSize(int* arr, int arrSize) {
  int numFreqs[100001] = {0};
  int numFreqsSize = 0;

  for (int i = 0; i < arrSize; ++i) {
    if (++numFreqs[arr[i]] == 1) {
      arr[numFreqsSize++] = arr[i];
    }
  }

  for (int i = 0; i < numFreqsSize; ++i) {
    arr[i] = numFreqs[arr[i]];
  }

  qsort(arr, numFreqsSize, sizeof(int), compare);

  int i = 0, left = arrSize / 2;
  while (left > 0) left -= arr[i++];

  return i;
}
