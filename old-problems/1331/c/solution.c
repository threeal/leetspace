#include <limits.h>
#include <stdlib.h>

int* gArr;
int compare(const void* a, const void* b) {
  return gArr[*(int*)a] - gArr[*(int*)b];
}

int* arrayRankTransform(int* arr, int arrSize, int* returnSize) {
  gArr = arr;

  int* idxs = malloc(arrSize * sizeof(int));
  for (int i = 0; i < arrSize; ++i) idxs[i] = i;

  qsort(idxs, arrSize, sizeof(int), compare);

  int prev = INT_MIN;
  int rank = 0;
  for (int i = 0; i < arrSize; ++i) {
    if (arr[idxs[i]] != prev) {
      prev = arr[idxs[i]];
      ++rank;
    }
    arr[idxs[i]] = rank;
  }

  *returnSize = arrSize;
  return arr;
}
